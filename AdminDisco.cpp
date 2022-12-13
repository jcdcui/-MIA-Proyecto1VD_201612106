#pragma once
#include <iostream>
//#include <fstream>
#include <string.h> 

#include "Estructura.cpp"

#include "ErrorT.cpp"

using namespace std;


/* Metodo que se encarga de crear una particion extendida, Devuelve -1 si falla y 0 si funciona
 * @param mbr_
 * @param auxParticion
 * @param direccion : ubicacion archivo binario
*/
int crearParticionExtendida(struct MBR *mbr_,struct Particion *auxParticion,char *direccion);

/** Crea una particion logica, Devuelve -1 si falla y 0 si funciona
 * @param mbr_ 
 * @param auxParticion
 * @param direccion : ubicacion archivo binario
*/
int crearParticionLogica(struct MBR *mbr_,struct Particion *auxParticion,char *direccion);

/* Funcion que devuelve un booleano para comprobar la existencia del nombre de una particion en un disco
 * @param QString direccion: ruta del archivo
 * @param QString nombre: nombre de la particion
 * @return true = si existe | false = si no existe
*/
bool existeParticion(char *direccion, char *nombre);

//---------------------------------------------------------------- Implementaticiones----------------------------------------------------------------

int crearParticionExtendida(struct MBR *mbr_, struct Particion *auxParticion, char *direccion){
       //---------modifico  mbr leido----------------------
     //------------------------------------ ---------------------------
    struct Particion primeraParticion;//sin analizaar se determina es la particion disponible
    struct Particion ParticionesArreglo[4];//arreglo 4 particiones
    //lleno aux arreglo particiones:--------
    ParticionesArreglo[0]= mbr_->mbr_partition_1;
    ParticionesArreglo[1]= mbr_->mbr_partition_2;
    ParticionesArreglo[2]= mbr_->mbr_partition_3;
    ParticionesArreglo[3]= mbr_->mbr_partition_4;
    //---------------------------------------
     bool flagParticion = false;//Flag para ver si hay una particion disponible
        bool flagExtendida = false;//Flag para ver si ya hay una particion extendida
        int numParticion = -1;//Que numero de particion es
    
        for(int i = 0; i < 4; i++){//verifico si hay extendida
            if (strcmp(ParticionesArreglo[i].part_type,"e")){
                flagExtendida = true;
                break;
            }
        }
        
        if(!flagExtendida){
            //Verificar si existe una particion disponible
            for(int i = 0; i < 4; i++){
                if(strcmp(ParticionesArreglo[i].part_status,"1")==0 && ParticionesArreglo[i].part_s>=auxParticion->part_s){
                    flagParticion = true;
                    numParticion = i;
                    break;
                }
            }
            
            if(flagParticion){
                //Verificar el espacio libre del disco
                int espacioUsado = 0;
                for(int i = 0; i < 4; i++){
                    if(strcmp(ParticionesArreglo[i].part_status,"1") == 0){
                       espacioUsado += ParticionesArreglo[i].part_s;
                    }
                }
           cout << "Espacio disponible: " << (mbr_->mbr_tamano - espacioUsado) <<" Bytes"<< endl;//antes: mbr_->mbr_s
           cout << "Espacio necesario:  " << auxParticion->part_s<< " Bytes" << endl;//size_bytes
                
                //Verificar que haya espacio suficiente para crear la particion
                if((mbr_->mbr_tamano - espacioUsado) >= auxParticion->part_s){
                    if(!(existeParticion(direccion,auxParticion->part_name))){//auxParticion->part_start
                        //FIRST FIT
                        if(strcmp(mbr_->dsk_fit,"ff") == 0){
                            strcpy(primeraParticion.part_type,"p");
                            strcpy(primeraParticion.part_fit,auxParticion->part_fit);
                            //Para start
                            if(numParticion == 0){
                                primeraParticion.part_start = sizeof(mbr_);
                            }else{//donde empieza si no es la particion en posicion 0
                                //OJO:podria cambiarse con: int, particion, int, particion
                                primeraParticion.part_start = ParticionesArreglo[numParticion-1].part_start + ParticionesArreglo[numParticion-1].part_s;
                            }
                            //---------------
                            primeraParticion.part_s = auxParticion->part_s;
                            strcpy(primeraParticion.part_status,"0");
                            strcpy(primeraParticion.part_name,auxParticion->part_name);
                            //---------------busca que particion modificar --------------------
                            if(numParticion == 0){
                                mbr_->mbr_partition_1 = primeraParticion;
                            }else if(numParticion == 1){
                                mbr_->mbr_partition_2 = primeraParticion;
                            }else if(numParticion == 2){
                                mbr_->mbr_partition_3 = primeraParticion;
                            }else if(numParticion == 3){
                                mbr_->mbr_partition_4 = primeraParticion;
                            }
                            //--------------- Se guarda de nuevo el MBR -------------------
                            FILE *fp;
                            //MBR masterboot;
                            fp = fopen(direccion, "rb");
                            if(fp == NULL){
                                cout<<"Error: el fichero no se puede abrir\n";
                                return -1;
                            }

                            fseek(fp,0,SEEK_SET);
                            fwrite(&mbr_,sizeof(MBR),1,fp);
                            
                            //------------------Se guarda la particion extendida--------------------------------
                            //OJO: recordar antes el mbr pero parece los .part_start vienen exactos , por eso se usa SEEK_SET
                            fseek(fp, primeraParticion.part_start,SEEK_SET); //primeraParticion ya q es la q acabamos manejar
                            struct EBR extendedBoot;
                            strcpy(extendedBoot.part_fit,primeraParticion.part_fit);//part_fit = al par fit de auxParticion
                            strcpy(extendedBoot.part_status,"0");
                            extendedBoot.part_start = primeraParticion.part_start;
                            extendedBoot.part_s = 0;
                            extendedBoot.part_next = -1;
                            strcpy(extendedBoot.part_name, "");
                            fwrite(&extendedBoot,sizeof(EBR),1,fp);
                            /* OJO:para el otro reporte parece
                            for(int i = 0; i < (primeraParticion.part_s - (int)sizeof(EBR)); i++){
                                fwrite(&buffer,1,1,fp);//buffer = '1'
                            }
                            */
                            //if(archivo == "principal") cout << "...\n" << "Particion extendida creada con exito"<< endl;
                            fclose(fp);
                            cout << "...\n" << "Particion extendida creada con exito"<< endl;
                            
                            
                        } 
                        //Best fit
                        else if(strcmp(mbr_->dsk_fit,"bf")){
                            int bestIndex = numParticion;
                            //mejor indice
                            for(int i = 0; i < 4; i++){
                                 
                                if(strcmp(ParticionesArreglo[i].part_status,"1") == 0 && ParticionesArreglo[i].part_s >=auxParticion->part_s){
                                    if(i != numParticion){                                       
                                        if(ParticionesArreglo[bestIndex].part_s > ParticionesArreglo[i].part_s){
                                            bestIndex = i;
                                            break;
                                        }
                                    }
                                }
                            }
                            //
                            //------------------buasca q particion modificar---------
                            strcpy(ParticionesArreglo[bestIndex].part_type,"e");
                            strcpy(ParticionesArreglo[bestIndex].part_fit,auxParticion->part_fit);
                            //start
                            if(bestIndex == 0){
                            ParticionesArreglo[bestIndex].part_start = sizeof(mbr_);
                            }else{
                            ParticionesArreglo[bestIndex].part_start = ParticionesArreglo[bestIndex-1].part_start + ParticionesArreglo[bestIndex-1].part_s;
                            }
                            ParticionesArreglo[bestIndex].part_s = auxParticion->part_s;
                            strcpy(ParticionesArreglo[bestIndex].part_status,"0");
                            strcpy(ParticionesArreglo[bestIndex].part_name,auxParticion->part_name);
                            
                            //-----------Se guarda de nuevo el MBR---------------
                            FILE *fp;
                            //MBR masterboot;
                            fp = fopen(direccion, "rb");
                            if(fp == NULL){
                                cout<<"Error: el fichero no se puede abrir\n";
                                return -1;
                            }

                            fseek(fp,0,SEEK_SET);
                            fwrite(&mbr_,sizeof(MBR),1,fp);
                            //-------Se guarda la particion extendida-----------
                            fseek(fp,ParticionesArreglo[bestIndex].part_start,SEEK_SET);
                            EBR extendedBoot;
                            strcpy(extendedBoot.part_fit,auxParticion->part_fit);
                            strcpy(extendedBoot.part_status,"0");
                            extendedBoot.part_start = ParticionesArreglo[bestIndex].part_start;
                            extendedBoot.part_s = 0;
                            extendedBoot.part_next = -1;
                            strcpy(extendedBoot.part_name, "");
                            fwrite(&extendedBoot,sizeof (EBR),1,fp);
                            /*
                            for(int i = 0; i < (auxParticion->part_s - (int)sizeof(EBR)); i++){//OJO: el casteo aqui q
                                fwrite(&buffer,1,1,fp);
                            }
                            */
                            //if(archivo == "principal") cout << "...\n" << "Particion extendida creada con exito"<< endl;
                            fclose(fp);
                            cout << "...\n" << "Particion extendida creada con exito"<< endl;
                        
                        }
                        //WORST FIT
                        else if(strcmp(mbr_->dsk_fit,"wf")){
                            int  worstIndex= numParticion;
                            //worstIndex
                            for(int i = 0; i < 4; i++){
                                if(strcmp(ParticionesArreglo[i].part_status,"1") && ParticionesArreglo[i].part_s>=auxParticion->part_s){//|| Part[i].part_start == -1
                                    if(i != numParticion){
                                        if(ParticionesArreglo[worstIndex].part_s < ParticionesArreglo[i].part_s){
                                            worstIndex = i;
                                            break;
                                        }
                                    }
                                }
                            }
                            strcpy(ParticionesArreglo[worstIndex].part_type,"e");
                            strcpy(ParticionesArreglo[worstIndex].part_fit,auxParticion->part_fit);
                            //start
                            if(worstIndex == 0){
                                ParticionesArreglo[worstIndex].part_start = sizeof(mbr_);
                            }else{
                                ParticionesArreglo[worstIndex].part_start = ParticionesArreglo[worstIndex-1].part_start+ ParticionesArreglo[worstIndex-1].part_s;
                            }
                            ParticionesArreglo[worstIndex].part_s = auxParticion->part_s;
                            strcpy(ParticionesArreglo[worstIndex].part_status,"0");
                            strcpy(ParticionesArreglo[worstIndex].part_name,auxParticion->part_name);
                            //Se guarda de nuevo el MBR
                            FILE *fp;
                            //MBR masterboot;
                            fp = fopen(direccion, "rb");
                            if(fp == NULL){
                                cout<<"Error: el fichero no se puede abrir\n";
                                return -1;
                            }
                            fseek(fp,0,SEEK_SET);
                            fwrite(&mbr_,sizeof(MBR),1,fp);
                            //--------Se guarda la particion extendida-----------
                            fseek(fp, ParticionesArreglo[worstIndex].part_start,SEEK_SET);
                            EBR extendedBoot;
                            strcpy(extendedBoot.part_fit,auxParticion->part_fit);
                            strcpy(extendedBoot.part_status,"0");
                            extendedBoot.part_start = ParticionesArreglo[worstIndex].part_start;
                            extendedBoot.part_s = 0;
                            extendedBoot.part_next = -1;
                            strcpy(extendedBoot.part_name, "");
                            fwrite(&extendedBoot,sizeof (EBR),1,fp);
                            /*
                            for(int i = 0; i < (auxParticion->part_s - (int)sizeof(EBR)); i++){//OJO:int
                                fwrite(&buffer,1,1,fp);
                            }
                            */
                            //if(archivo == "principal") cout << "...\n" << "Particion extendida creada con exito"<< endl;
                            fclose(fp);
                            cout << "...\n" << "Particion extendida creada con exito"<< endl;
                        }
                    }else{
                        cout << "ERROR ya existe una particion con ese nombre" << endl;
                    }
                }else{
                    cout << "ERROR la particion a crear excede el tamano libre" << endl;
                }
            }else{
                cout << "ERROR: Ya existen 4 particiones, no se puede crear otra" << endl;
                cout << "Elimine alguna para poder crear una" << endl;
            }
        }else{
            cout << "ERROR ya existe una particion extendida en este disco" << endl;
        }
    //fclose(fp);
    return 0;
}


int crearParticionLogica(struct MBR *mbr_,struct Particion *auxParticion,char *direccion){
    //------------------------------------ ---------------------------
    struct Particion primeraParticion;//sin analizaar se determina es la particion disponible
    struct Particion ParticionesArreglo[4];//arreglo 4 particiones
    //lleno aux arreglo particiones:--------
    ParticionesArreglo[0]= mbr_->mbr_partition_1;
    ParticionesArreglo[1]= mbr_->mbr_partition_2;
    ParticionesArreglo[2]= mbr_->mbr_partition_3;
    ParticionesArreglo[3]= mbr_->mbr_partition_4;
    //---------------------------------------
    bool flagParticion = false;//Flag para ver si hay una particion disponible
        bool flagExtendida = false;//Flag para ver si ya hay una particion extendida
        int numExtendida = -1;//Que numero de particion es
    
    //---------verifico si hay extendida------------
        for(int i = 0; i < 4; i++){
            if (strcmp(ParticionesArreglo[i].part_type,"e")){
                numExtendida = i;
                break;
            }
        }

        if(existeParticion(direccion,auxParticion->part_name)) {ErrorT("existe ya una particion extendida"); return -1;}
        if(numExtendida == -1){ErrorT("No se encontro particion para guardar la logica"); return -1;}   
        EBR extendedBoot;
        int cont = ParticionesArreglo[numExtendida].part_start;//byte donde inicia particion extendida
        FILE *fp;
        //MBR masterboot;
        fp = fopen(direccion, "rb");
        if(fp == NULL){
            ErrorT("No se encuentra este disco");
            return -1;
        }
        fseek(fp,cont,SEEK_SET);
        fread(&extendedBoot,sizeof(EBR),1,fp);
        if(extendedBoot.part_s == 0){//si es la primera vez
            if(ParticionesArreglo[numExtendida].part_s < auxParticion->part_s){
                ErrorT("la particion exsede el tamaño"); return -1;
            }else{
                strcpy(extendedBoot.part_status,"0");
                strcpy(extendedBoot.part_fit,auxParticion->part_fit);
                extendedBoot.part_start = ftell(fp) - sizeof(EBR); //Para regresar al inicio de la extendida
                extendedBoot.part_s = auxParticion->part_s;
                extendedBoot.part_next = -1;
                strcpy(extendedBoot.part_name,auxParticion->part_name);

                fseek(fp,ParticionesArreglo[numExtendida].part_start,SEEK_SET);
                fwrite(&extendedBoot,sizeof(EBR),1,fp);
            }
        }else{
        
            //lee hasta encuentre el ultimo ebr 
            while((extendedBoot.part_next != -1) && (ftell(fp) < (ParticionesArreglo[numExtendida].part_s + ParticionesArreglo[numExtendida].part_start))){
                fseek(fp,extendedBoot.part_next,SEEK_SET);
                fread(&extendedBoot,sizeof(EBR),1,fp);
            }
            //ebr + espacio particion
            int espacioNecesario = extendedBoot.part_start + extendedBoot.part_s + auxParticion->part_s;
            //debe caber el espacioNecesario
            if(espacioNecesario <= (ParticionesArreglo[numExtendida].part_s + ParticionesArreglo[numExtendida].part_start) ){
                extendedBoot.part_next = extendedBoot.part_start + extendedBoot.part_s;
                //escribimos el next del ultimo ebr
                fseek(fp,ftell(fp)-sizeof(EBR),SEEK_SET);//situamos en la posicion del next del utlimo ebr
                fwrite(&extendedBoot,sizeof(EBR),1,fp);//escribimos ahora con el nuevo next
                //Escribimos el nuevo ebr
                fseek(fp,extendedBoot.part_start+extendedBoot.part_s,SEEK_SET);
                strcpy(extendedBoot.part_status,"0");
                strcpy(extendedBoot.part_fit,auxParticion->part_fit);
                extendedBoot.part_start = ftell(fp);
                extendedBoot.part_s = auxParticion->part_s;
                extendedBoot.part_next = -1;
                strcpy(extendedBoot.part_name,auxParticion->part_name);
                fwrite(&extendedBoot,sizeof(EBR),1,fp);
                fclose(fp);
            }else{
                ErrorT("la particion logica a crear excede el espacio disponible");
                return -1;
            }
        }
     return 0;
}



bool existeParticion(char *direccion, char *nombre){
    
    return false;
}



/*
bool existeParticion(char *direccion, char *nombre){
    int extendida = -1;
//---------------Abre y lee mbr----------------------
    ifstream ArchivoBinario;
    ArchivoBinario.open(guardaNombre, ios::in | ios::binary);
    if (!ArchivoBinario)
    {
        cout<<"error al abrir archivo\n";
        return false;
    }
    struct MBR itrRegistro_rb;
    //lee primer registro
    ArchivoBinario.read(reinterpret_cast< char * >(&itrRegistro_rb),sizeof(MBR));
    ArchivoBinario.close();

    struct Particion ParticionesArreglo[4];//arreglo 4 particiones
    //lleno aux arreglo particiones:--------
    ParticionesArreglo[0]= itrRegistro_rb.mbr_partition_1;
    ParticionesArreglo[1]= itrRegistro_rb.mbr_partition_2;
    ParticionesArreglo[2]= itrRegistro_rb.mbr_partition_3;
    ParticionesArreglo[3]= itrRegistro_rb.mbr_partition_4;
    for(int i = 0; i < 4; i++){
            if(strcmp(ParticionesArreglo[i].part_name,nombre) == 0){
                return true;
            }else if(strcmp(ParticionesArreglo[i].part_type,"E")){
                extendida = i;
            }
        }
        //-------------AQUI VA PARA PARTICION EXTENDIDA-------------
        //if(extendida != -1){
        //    EBR extendedBoot;
        //}
        //------------A------------------
    
    return false;
}
*/