//OJO: limpiaComando en los errores verificarparam
//OJO:limpiar comando
//OJO:terminar existeParticion()

//OJO:agrega = en lugar de ->
//OJO: Probar mkdisk y fdisk
//OJO: ver como crea el aux los discos en las direcciones de la compu

/*
    Tiempo con <ctime> ,   https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm#
*/
#pragma once
#include <iostream>
//quito include ctime
#include <fstream>
#include <string.h> 

//---------------Include de archivos -----------------------
#include "AdminDisco.cpp"
#include "Estructura.cpp"
#include "Mount.cpp"

//----------------------------------------------------------

//#include <stddef.h>
//NULL

using std::fstream;
using std::ofstream;
using std::ifstream; // flujo de archivo de entrada
using namespace std;
//-------------variables---------------------

     char Tmkdisk[]={"mkdisk"};
     char Ts[]={"-s"};
     char Tf[]={"-f"};
     char Tu[]={"-u"};
     char Tpath[]={"-path"};
     char Trmdisk[]={"rmdisk"};
     char Tfdisk[]={"fdisk"};
     char Tt[]={"-t"};
     char Tdeletee[]={"-delete"};
     char Tname[]={"-name"};
     char Tadd[]={"-add"};
     char Tmount[]={"mount"};
     char Tunmount[]={"unmount"};
     char Tid[]={"-id"};
     char Tmkfs[]={"mkfs"};
     char Ttype[]={"-type"};
     char Tfs[]={"-fs"};
     char Tlogin[]={"login"};
     char Tusr[]={"-usr"};
     char Tpass[]={"pass"};
     char Tlogout[]={"logout"};
     char Tmkgrp[]={"mkgrp"};
     char Trep[]={"rep"};
     char Truta[]={"-ruta"};
     char Trmgrp[]={"rmgrp"};
     char Tmkusr[]={"mkusr"};
     char Tgrp[]={"-grp"};
     char Trmusr[]={"rmusr"};
     char Tchmod[]={"chmod"};
     char Tugo[]={"-ugo"};
     char Tr[]={"-r"};
     char Tmkfile[]={"mkfile"};
     char Tcont[]={"-cont"};
     char Tcat[]={"cat"};
     char TfileN[]={"-fileN"};
     char Tremovee[]={"remove"};
     char Tedit[]={"edit"};
     char Trenamee[]={"rename"};
     char Tmkdir[]={"mkdir"};
     char Tp[]={"p"};
     char Tcopyy[]={"copy"};
     char Tmovee[]={"move"};
     char Tdestino[]={"-destino"};
     char Tfindd[]={"find"};
     char Tchown[]={"chown"};
     char Tchgrp[]={"chgrp"};
     char Tpausee[]={"pause"};
//-----------variables para comparar------------

char auxcompar[10]={'\0'};
//----------  --------------

int opcion=0;
char carac0='\0';
int contComandos=0;
/**
 * Guarda nombre de los path
 */
char guardaNombre[20]={'\0'};
char guardaDireccion[90]={'\0'};
char guardaNombrePadre[20]={'\0'};

/**
 * Guarda numeracion de id unico de los discos
*/
int mbrRandom =0;

//---------------------structs----------------------------

struct comandoDisco{
    char tipo[10]={'\0'};
    //por el momento solo para mkdisk 
    int Ts=0;
    char Tf[15]={'\0'};
    char Tu[15]={'\0'};
    char Tpath[50]={'\0'};//
    
    char Tname[15]={'\0'};
    char Tid[15]={'\0'};
    char Truta[15]={'\0'};
    char Tt[15]={'\0'};
    char Tdelete[15]={'\0'};
    int Tadd;

    char Ttype[15]={'\0'};
    char Tfs[15]={'\0'};

    char Tusr[15]={'\0'};
    char Tpass[15]={'\0'};

    char Tgrp[15]={'\0'};

    int Tugo=0;
    bool Tr=false;
    char Tcont[15]={'\0'};

    char Tfile[15]={'\0'};
    int TfileN=0;
    bool Tp = false;
    char Tdestino[15]={'\0'};

}comandos[50];

struct comandoDisco comando;

//quito esturcturas

//---------------------metodos--------------------------------
/**
 * lee entrada de   archivo entrada
*/
void leerEntrada(char *pathArchivo);

/**
 * @param: auxtoken, lo midifica de una
 * @param: banderaFlecha , cambia la var leer entrada
 * @return: contciclos si se reinicia por q guardo el token  sino restura el mismo contciclo entro
*/
int VerificarTok( char *auxtoken,int contciclos,char *anteriortoken,bool *banderaflecha);
bool esOperador(char *auxoperador);

/**
 * Guarda los parametros encuentra, llama a los metodos Ejecutar(Comando)() tambien
 * @param:  anteriorToken , sera el nombre parametro
 * @param: auxToken, sera el valor del parametro
*/
int VerificarParametro(char *anteriorToken,char* auxToken,bool finalLinea);
//----------------------------------------------------------------------------------------------------------------


void crearDirectorio(char *direccion);

//----------------------------------------------------------------------------------------------------------------
void buscarNombre(char *direccion);
/** busca y guarda en guardaNombrePadre el nombre de la carpeta raiz de char *direccion
 *
*/
void buscaNombrePadre(char *direccion);

void buscaDireccion(char *direccion);

//lee archivo disco
void ReporteConsola();
/**
 * Crea o abre un Discko como archivo binario 
*/
int EjecutarMkdisk();

//-----------------------------------fdixk-------------
/** Devuelve -1 si falla y 0 si funciona  
*/
int EjecutarFdisk();
/** Devuelve -1 si falla y 0 si funciona
 * @param mbr_
 * @param auxParticion
*/
int creaParticionPrimaria(struct MBR *mbr_,struct Particion *auxParticion,char *direccion);
//------------------------Mount----------------------------------------
/** Devuelve -1 si falla y 0 si funciona  
 * 
*/
int EjecutarMount();
/** Devuelve -1 si falla y 0 si funciona
*/
int EjecutarUnmount();

//----------------------------------------pueden ir en otro archivo --------------------------------------------------------
void LimpiaString(char *auxtoken);

void LimpiaComando(struct comandoDisco *comandoL);

void A_minusculas(char *cadena);

//quito crearParticionExtendida
//quito existeParticion
//------------------------------------------------------------------------------------------------------------------------

int main(int argc, char const *argv[])
{
    /*  TIEMPO:
time_t now = time(0); //fecha y tiempo actual segun sistema
char* dt = ctime(&now); //conviete a string ctime
cout<<"local date and time:"<<dt<<endl;
*/

/*  ALEATORIO:
int aleatorio;
srand(time(NULL)); // prepara para generar aleatorio, con tiempo actual
aleatorio=1+rand()%100; // entre 1 y 100
cout<<aleatorio<<endl;
*/
    char Ingresoexce[50]={'\0'};
    cout  << "****************** DATO *****************" << endl;
    cout  << "*\t\t\t\t\t*" << endl;
    cout  << "*\t Juan Carlos Gomez Chanax\t*" << endl;
    cout  << "*\t\t  201612106 \t\t*" << endl;
    cout  << "*\t\t\t\t\t*" << endl;
    cout  << "*****************************************" << endl<<endl;
    cout  << "=========> Escriba un comando <========="<<endl<<endl;
    std::cin.getline(Ingresoexce,sizeof(Ingresoexce),'\n');//OJO:ver bien funcionalidad sizeof, parece mejor limpiar arreglo char con '\0' q con sizeof
    //exec -path=/escritorio/prueba.algo
    
    //OJO manejar el exec primero y mandarlo a analizar
    leerEntrada(Ingresoexce);//puede pasar ruta del archivo

    
    return 0;
}

bool esOperador(char *auxoperador){
     char flecha[]={"="};
     char interrogacion[]={"?"};
     char asterisco[]={"*"};

    if(strcmp(flecha,auxoperador) == 0){
         cout<<"> encontro:"<<flecha<<":"<<auxoperador<<endl;
        return true;
    }else if(strcmp(interrogacion,auxoperador) == 0){
        cout<<"? encontro:"<<interrogacion<<"="<<auxoperador<<endl;
        return true;
    }else if(strcmp(asterisco,auxoperador) == 0){
        cout<<"* encontro:"<<asterisco<<"="<<auxoperador<<endl;
        return true;
    }
    else{
        cout<<"fallo operador en:"<<":"<<auxoperador<<endl;
        return false;
    }
    cout<<"error esOperador"<<endl;
    return false;

}

int VerificarTok( char *auxtoken,int contciclos,char *anteriortoken,bool *banderaflecha){
     //48

    if (auxtoken[0]=='\0')//aux vacio, mas para espacios al principio o muchos, o muchos saltos de linea
    {
        
    } else{ //--------------------ver que tipo-------------------------
        //
        A_minusculas(auxtoken);//a minusculas el token actual

        if(strcmp(Tmkdisk,auxtoken) == 0){//igual a ->1
            cout<<"mkdisk detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tmkdisk);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
            
        }//OJO: situacion -path->  pegados no tomada en cuenta
        else if(strcmp(Ts,auxtoken) == 0){//igual a ->2
            cout<<"s detected"<<endl;
            strcpy(anteriortoken,Ts);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
        }
        else if(strcmp(Tf,auxtoken) == 0){//igual a ->3
            cout<<"f detected"<<endl;
            strcpy(anteriortoken,Tf);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
        }
        else if(strcmp(Tu,auxtoken) == 0){//igual a ->4
            cout<<"u detected"<<endl;
            strcpy(anteriortoken,Tu);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
        }
        else if(strcmp(Tpath,auxtoken) == 0){//igual a ->5
            cout<<"path detected"<<endl;
            strcpy(anteriortoken,Tpath);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
        }
        else if(strcmp(Trmdisk,auxtoken) == 0){//igual a ->6
            cout<<"rmdisk detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Trmdisk);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
            
        }
        else if(strcmp(Tfdisk,auxtoken) == 0){//igual a ->7
            cout<<"fdisk detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tfdisk);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
            
        }
        else if(strcmp(Tt,auxtoken) == 0){//igual a ->8
            cout<<"t detected"<<endl;
            strcpy(anteriortoken,Tt);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)

        }else if(strcmp(Tdeletee,auxtoken) == 0){//igual a ->9
            cout<<"deletee detected"<<endl;
            strcpy(anteriortoken,Tdeletee);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)

        }else if(strcmp(Tname,auxtoken) == 0){//igual a ->10
            cout<<"name detected"<<endl;
            strcpy(anteriortoken,Tname);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)

        }else if(strcmp(Tadd,auxtoken) == 0){//igual a ->11
            cout<<"add detected"<<endl;
            strcpy(anteriortoken,Tadd);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            
        }else if(strcmp(Tmount,auxtoken) == 0){//igual a ->12
            cout<<"mount detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tmount);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
            
        }else if(strcmp(Tunmount,auxtoken) == 0){//igual a ->13
            cout<<"unmount detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tunmount);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
            
        }else if(strcmp(Tid,auxtoken) == 0){//igual a ->14
            cout<<"id detected"<<endl;
            strcpy(anteriortoken,Tid);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)

        }else if(strcmp(Tmkfs,auxtoken) == 0){//igual a ->15
            cout<<"mkfs detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tmkfs);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
            

//-----------------Comandos Administrador Usuarios---------------------------            
   
        }else if(strcmp(Ttype,auxtoken) == 0){//igual a ->16
            cout<<"type detected"<<endl;
            strcpy(anteriortoken,Ttype);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
    
        }else if(strcmp(Tfs,auxtoken) == 0){//igual a ->17
            cout<<"fs detected"<<endl;
            strcpy(anteriortoken,Tfs);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
           
        }else if(strcmp(Tlogin,auxtoken) == 0){//igual a ->18
            cout<<"login detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tlogin);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
            
        }else if(strcmp(Tusr,auxtoken) == 0){//igual a ->19
            cout<<"usr detected"<<endl;
            strcpy(anteriortoken,Tusr);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
     
        }else if(strcmp(Tpass,auxtoken) == 0){//igual a ->20
            cout<<"pass detected"<<endl;
            strcpy(anteriortoken,Tpass);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
 
        }else if(strcmp(Tlogout,auxtoken) == 0){//igual a ->21
            cout<<"logout detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tlogout);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
            
        }else if(strcmp(Tmkgrp,auxtoken) == 0){//igual a ->22
            cout<<"mkgrp detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tmkgrp);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
            
        }else if(strcmp(Trep,auxtoken) == 0){//igual a ->23
            cout<<"rep detected"<<endl;
            //guarda rep tipo
            strcpy(comandos[contComandos].tipo,Trep);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //ReporteConsola();
            
             
        }else if(strcmp(Truta,auxtoken) == 0){//igual a ->24
            cout<<"ruta detected"<<endl;
            strcpy(anteriortoken,Truta);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)

        }
        /*OJO: manejar el exec aqui , poner otro aqui
        else if(strcmp(Texec,auxtoken) == 0){//igual a ->25
            cout<<"exec detected"<<endl;
            //guarda exec tipo
            strcpy(comandos[contComandos].tipo,Texec);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)        
             
        }
        */
        else if(strcmp(Trmgrp,auxtoken) == 0){//igual a ->26
            cout<<"rmgrp detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Trmgrp);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             
             
        }else if(strcmp(Tmkusr,auxtoken) == 0){//igual a ->27
            cout<<"mkusr detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tmkusr);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             
             
        }else if(strcmp(Tgrp,auxtoken) == 0){//igual a ->28
            cout<<"grp detected"<<endl;
            strcpy(anteriortoken,Tgrp);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
             
        }else if(strcmp(Trmusr,auxtoken) == 0){//igual a ->29
            cout<<"rmusr detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Trmusr);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             

//---------------Comandos Usuario root ---------------------------------

        }else if(strcmp(Tchmod,auxtoken) == 0){//igual a ->30
            cout<<"chmod detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tchmod);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             
             
        }else if(strcmp(Tugo,auxtoken) == 0){//igual a ->31
            cout<<"ugo detected"<<endl;
            strcpy(anteriortoken,Tugo);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
             
        }else if(strcmp(Tr,auxtoken) == 0){//igual a ->32
            cout<<"r detected"<<endl;
            strcpy(anteriortoken,Tr);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
             
        }else if(strcmp(Tmkfile,auxtoken) == 0){//igual a ->33
            cout<<"mkfile detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tmkfile);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             
             
        }else if(strcmp(Tcont,auxtoken) == 0){//igual a ->34
            cout<<"cont detected"<<endl;
            strcpy(anteriortoken,Tcont);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
             
        }else if(strcmp(Tcat,auxtoken) == 0){//igual a ->35
            cout<<"cat detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tcat);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             
             
        }else if(strcmp(TfileN,auxtoken) == 0){//igual a ->36
            cout<<"fileN detected"<<endl;
            strcpy(anteriortoken,TfileN);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
             
        }else if(strcmp(Tremovee,auxtoken) == 0){//igual a ->37
            cout<<"remove detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tremovee);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             
             
        }else if(strcmp(Tedit,auxtoken) == 0){//igual a ->38
            cout<<"edit detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tedit);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             
            
        }else if(strcmp(Trenamee,auxtoken) == 0){//igual a ->39
            cout<<"rename detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Trenamee);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             
             
        }else if(strcmp(Tmkdir,auxtoken) == 0){//igual a ->40
            cout<<"mkdir detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tmkdir);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             
             
        }else if(strcmp(Tp,auxtoken) == 0){//igual a -> 41
            cout<<"p detected"<<endl;
            strcpy(anteriortoken,Tp);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
             
        }else if(strcmp(Tcopyy,auxtoken) == 0){//igual a ->42
            cout<<"copy detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tcopyy);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             
             
        }else if(strcmp(Tmovee,auxtoken) == 0){//igual a ->43
            cout<<"move detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tmovee);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             
             
        }else if(strcmp(Tdestino,auxtoken) == 0){//igual a ->44
            cout<<"destino detected"<<endl;
            strcpy(anteriortoken,Tdestino);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
             
        }else if(strcmp(Tfindd,auxtoken) == 0){//igual a ->45
            cout<<"find detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tfindd);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             
             
        }else if(strcmp(Tchown,auxtoken) == 0){//igual a ->46
            cout<<"chown detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tchown);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             
             
        }else if(strcmp(Tchgrp,auxtoken) == 0){//igual a ->47
            cout<<"chgrp detected"<<endl;
            //guarda mkdisk tipo
            strcpy(comandos[contComandos].tipo,Tchgrp);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            //CrearAbrirDisk();
             
             
        }else if(strcmp(Tpausee,auxtoken) == 0){//igual a ->48
            
            strcpy(comandos[contComandos].tipo,Tpausee);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
             
        }
        //OJO:falta aqui comandos DISCO,si es q hay
        
        else{//---------------operadores o cualquier otro---------------------

            //_______________operadores_______________________________________
            char flecha[]={"="};
            char interrogacion[]={"?"};
            char asterisco[]={"*"};

            if(strcmp(flecha,auxtoken) == 0){
                cout<<"encontro flecha:"<<flecha<<":"<<auxtoken<<endl;
                *banderaflecha = true;   
                
            }
            /*
            else if(strcmp(interrogacion,auxtoken) == 0){
                cout<<"? encontro:"<<interrogacion<<"="<<auxtoken<<endl;
                 
            }else if(strcmp(asterisco,auxtoken) == 0){
                cout<<"* encontro:"<<asterisco<<"="<<auxtoken<<endl;
                 
            }    
            */        
             else{ 
        //-----------en espacio blanco: viene numero , letras o direccion o etc en auxToken----------------
                cout<<"cualquier otro:"<<auxtoken<<endl;
            }

        }//fin operadores o cuaquier otro


      //   LimpiaString(auxcompar);

        LimpiaString(auxtoken);
        contciclos=0;
        return contciclos;
    } //fin else , ver que tipo-----------
    //cout<<"fin verificartok sin cambios"<<endl;
    return contciclos;

}

int VerificarParametro(char *anteriorToken,char* auxToken1,bool finalLinea){
    //mkdisk
    strcpy(comando.tipo,comandos[contComandos].tipo);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
    //-------------------------A minusculas---------------------------------------
    char auxToken[50]={'\0'};
    if (strcmp(Tpath,anteriorToken)==0 || strcmp(Tname,anteriorToken)==0 || strcmp(Tid,anteriorToken)==0 
    || strcmp(Tusr,anteriorToken)==0 || strcmp(Tpass,anteriorToken)==0 || strcmp(Tgrp,anteriorToken)==0 
    || strcmp(Tcont,anteriorToken)==0 || strcmp(TfileN,anteriorToken)==0 || strcmp(Tdestino,anteriorToken)==0)
    {
        strcpy(auxToken,auxToken1);
    } else {//si es cualqquiera menos los del if convierto a minuscula su contenido
        strcpy(auxToken,auxToken1);
        A_minusculas(auxToken);
    }
    //----------------------------------------------------------------
    if(strcmp(Tmkdisk,comando.tipo) == 0){//
        if (strcmp(Ts,anteriorToken)==0)
        {
            comando.Ts = atoi(auxToken);
        
        }else if (strcmp(Tf,anteriorToken)==0)
        {
            strcpy(comando.Tf,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
        }else if (strcmp(Tu,anteriorToken)==0)
        {
            strcpy(comando.Tu,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            
        }else if (strcmp(Tpath,anteriorToken)==0)
        {
            strcpy(comando.Tpath,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            
        }else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Ts > 0 && comando.Tpath[0] !='\0')
            {
                //if else if , else para validar -f venga correctamente
                if (comando.Tf[0] == '\0')
                {
                    strcpy(comando.Tf,"ff");
                }else if (strcmp(comando.Tf,"bf")==0)
                {
                    strcpy(comando.Tf,"bf");
                } else if (strcmp(comando.Tf,"wf")==0)
                {
                    strcpy(comando.Tf,"wf");
                } else if (strcmp(comando.Tf,"ff")==0)
                {
                    strcpy(comando.Tf,"ff");
                }
                
                else{//biene un error 
                    cout<<comando.tipo<<" este fit no existe";
                    LimpiaString(comandos[contComandos].tipo);
                    return -1;
                }

                if (comando.Tu[0] != '\0')
                {
                    if (comando.Tu[0] == 'k')
                    {
                    }
                    else if (comando.Tu[0] == 'm')
                    {
                    }
                    else{
                        cout<<comando.tipo<<" error no se puede generar este comando";
                        LimpiaString(comandos[contComandos].tipo);
                        return -1;
                    }
                }
               
                //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                comandos[contComandos] = comando; 
                LimpiaComando(&comando);
                EjecutarMkdisk();
                contComandos++;
                
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }

    }//OJO: situacion -path->  pegados no tomada en cuenta
    else if(strcmp(Trmdisk,comando.tipo) == 0){//
        
        if (strcmp(Tpath,anteriorToken)==0)
        {
            strcpy(comando.Tpath,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            
        }else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tpath[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }
    }else if(strcmp(Tfdisk,comando.tipo) == 0){//
        if (strcmp(Ts,anteriorToken)==0)
        {
            comando.Ts = atoi(auxToken);

        }else if (strcmp(Tu,anteriorToken)==0)
        {
            cout <<"U en fdisk:"<<auxToken <<endl; 
            strcpy(comando.Tu,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            
        }else if (strcmp(Tpath,anteriorToken)==0)
        {
            strcpy(comando.Tpath,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            
        }else if (strcmp(Tt,anteriorToken)==0)
        {
            strcpy(comando.Tt,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            
        }else if (strcmp(Tf,anteriorToken)==0)
        {
            strcpy(comando.Tf,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            
        }else if (strcmp(Tdeletee,anteriorToken)==0)
        {
            strcpy(comando.Tdelete,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            
        }else if (strcmp(Tname,anteriorToken)==0)
        {
            strcpy(comando.Tname,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
            
        }else if (strcmp(Tadd,anteriorToken)==0)
        {
            comando.Tadd = atoi(auxToken);
        }
        else{
            cout<<comando.tipo<<",error el comando no se reconoce:"<<anteriorToken<<endl;
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Ts >0 && comando.Tpath[0] !='\0' && comando.Tname[0] !='\0')
            {   
                //
                if (comando.Tf[0] == '\0')
                {
                    strcpy(comando.Tf,"worstfit");

                }else if (strcmp(comando.Tf,"bestfit")==0 ||strcmp(comando.Tf,"worstfit")==0 || strcmp(comando.Tf,"firstfit")==0)
                {
                    
                }else{//biene un error 
                    cout<<comando.tipo<<" error no se puede generar este comando";
                    LimpiaString(comandos[contComandos].tipo);
                    return -1;
                }
                //
                if (comando.Tu[0] != '\0')
                {
                    if (comando.Tu[0] == 'k') {comando.Ts=comando.Ts*1024;}
                    else if (comando.Tu[0] == 'm') { comando.Ts=comando.Ts*1048576;}
                    else if (comando.Tu[0] == 'b') {}
                    else{
                        cout<<comando.tipo<<" error no se puede generar este comando";
                        LimpiaString(comandos[contComandos].tipo);
                        return -1;
                    }
                    //kylobyt = 1024 bytes
                    //megabyte = 1048576 bytes
                } else{comando.Ts=comando.Ts*1024;}
                //
                if (comando.Tt[0] == '\0')
                {
                    strcpy(comando.Tt,"p");

                }else if (strcmp(comando.Tt,"p")==0 ||strcmp(comando.Tt,"e")==0 || strcmp(comando.Tt,"l")==0)
                {
                    
                }else{//biene un error 
                    cout<<comando.tipo<<" error no se puede generar este comando";
                    LimpiaString(comandos[contComandos].tipo);
                    return -1;
                }
                //
                if (comando.Tdelete[0] != '\0')
                {
                    if (comando.Tadd != 0)
                    {
                        cout<<comando.tipo<<" error no se puede generar este comando";
                        LimpiaString(comandos[contComandos].tipo);
                        return -1;
                    }
                    if (strcmp(comando.Tdelete,"full")==0)
                    {
                        
                    
                    }else{//biene un error 
                        cout<<comando.tipo<<" error no se puede generar este comando";
                        LimpiaString(comandos[contComandos].tipo);
                        return -1;
                    }
                }
                
                //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                comandos[contComandos] = comando;
                LimpiaComando(&comando);
                EjecutarFdisk();
                contComandos++;
                
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }                     
    }else if(strcmp(Tmount,comando.tipo) == 0){//
            
        if (strcmp(Tpath,anteriorToken)==0)
        {
           strcpy(comando.Tpath,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }else if (strcmp(Tname,anteriorToken)==0)
        {
            strcpy(comando.Tname,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)   
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tpath[0] !='\0' && comando.Tname[0] !='\0')
            {
                //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                comandos[contComandos] = comando;
                LimpiaComando(&comando);
                EjecutarMount();
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }
    }else if(strcmp(Tunmount,comando.tipo) == 0){// 
        if (strcmp(Tid,anteriorToken)==0)
        {
            strcpy(comando.Tid,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tid[0] != '\0' )
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }
    }else if(strcmp(Tmkfs,comando.tipo) == 0){//
        if (strcmp(Tid,anteriorToken)==0)
        {
           strcpy(comando.Tid,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }else if (strcmp(Ttype,anteriorToken)==0)
        {
            strcpy(comando.Ttype,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)   
        }
        else if (strcmp(Tfs,anteriorToken)==0)
        {
            strcpy(comando.Tfs,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)   
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tid[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }
    }
        //-----------------Comandos Administrador Usuarios---------------------------            

    else if(strcmp(Tlogin,comando.tipo) == 0){//igual a ->18
        if (strcmp(Tusr,anteriorToken)==0)
        {
           strcpy(comando.Tusr,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }else if (strcmp(Tpass,anteriorToken)==0)
        {
            strcpy(comando.Tpass,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)   
        }
        else if (strcmp(Tid,anteriorToken)==0)
        {
            strcpy(comando.Tid,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)   
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tusr[0] !='\0' && comando.Tpass[0] !='\0' && comando.Tid[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }
    } else if (strcmp(Tlogout,comando.tipo) == 0)
    {
        if (finalLinea)
        {
            contComandos++;
        }else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }

    }
    else if(strcmp(Tmkgrp,comando.tipo) == 0){//igual a ->22
        if (strcmp(Tname,anteriorToken)==0)
        {
           strcpy(comando.Tname,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tname[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }
    }else if(strcmp(Trep,comando.tipo) == 0){//igual a ->23
        
        
    } else if(strcmp(Trmgrp,comando.tipo) == 0){//igual a ->26
        if (strcmp(Tname,anteriorToken)==0)
        {
           strcpy(comando.Tname,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tname[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }
    }else if(strcmp(Tmkusr,comando.tipo) == 0){//igual a ->27
        if (strcmp(Tusr,anteriorToken)==0)
        {
           strcpy(comando.Tusr,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }else if (strcmp(Tpass,anteriorToken)==0)
        {
            strcpy(comando.Tpass,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)   
        }
        else if (strcmp(Tgrp,anteriorToken)==0)
        {
            strcpy(comando.Tgrp,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)   
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tusr[0] !='\0' && comando.Tpass[0] !='\0' && comando.Tgrp[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;  
            }
            
        }else{//es espacio en blanco

        }
        
    }else if(strcmp(Trmusr,comando.tipo) == 0){//igual a ->29
        if (strcmp(Tusr,anteriorToken)==0)
        {
           strcpy(comando.Tusr,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tusr[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }

        //---------------Comandos Usuario root ---------------------------------

    }else if(strcmp(Tchmod,comando.tipo) == 0){//igual a ->30
        if (strcmp(Tpath,anteriorToken)==0)
        {
           strcpy(comando.Tpath,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }else if (strcmp(Tugo,anteriorToken)==0)
        {
            comando.Tugo = atoi(auxToken);
        }
        else if (strcmp(Tr,anteriorToken)==0)
        {
            comando.Tr = true; //de la libreria string copia al primer param el param 2 desde 0 size(segundo)   
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tpath[0] !='\0' && comando.Tugo !=0)
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }
        
    }else if(strcmp(Tmkfile,comando.tipo) == 0){//igual a ->33
        if (strcmp(Tpath,anteriorToken)==0)
        {
           strcpy(comando.Tpath,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else if (strcmp(Tr,anteriorToken)==0)
        {
            comando.Tr = true; //de la libreria string copia al primer param el param 2 desde 0 size(segundo)   
        }
        else if (strcmp(Ts,anteriorToken)==0)
        {
            comando.Ts = atoi(auxToken);
        }
        else if (strcmp(Tcont,anteriorToken)==0)
        {
            strcpy(comando.Tcont,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tpath[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }
        
    }else if(strcmp(Tcat,comando.tipo) == 0){//igual a ->35
        if (strcmp(TfileN,anteriorToken)==0)
        {
           strcpy(comando.Tfile,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
           comando.TfileN = atoi(auxToken);
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tfile[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }   
    }else if(strcmp(Tremovee,comando.tipo) == 0){//igual a ->37
        if (strcmp(Tpath,anteriorToken)==0)
        {
           strcpy(comando.Tpath,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tpath[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }   
    }else if(strcmp(Tedit,comando.tipo) == 0){//igual a ->38
        if (strcmp(Tpath,anteriorToken)==0)
        {
           strcpy(comando.Tpath,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else if (strcmp(Tcont,anteriorToken)==0)
        {
           strcpy(comando.Tcont,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tpath[0] !='\0' && comando.Tcont[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }   
        
    }else if(strcmp(Trenamee,comando.tipo) == 0){//igual a ->39
        if (strcmp(Tpath,anteriorToken)==0)
        {
           strcpy(comando.Tpath,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else if (strcmp(Tname,anteriorToken)==0)
        {
           strcpy(comando.Tname,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tpath[0] !='\0' && comando.Tname[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }  
        
    }else if(strcmp(Tmkdir,comando.tipo) == 0){//igual a ->40
        if (strcmp(Tpath,anteriorToken)==0)
        {
           strcpy(comando.Tpath,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else if (strcmp(Tp,anteriorToken)==0)
        {
            comando.Tp = true;
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tpath[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }  
        
    }else if(strcmp(Tcopyy,comando.tipo) == 0){//igual a ->42
        if (strcmp(Tpath,anteriorToken)==0)
        {
           strcpy(comando.Tpath,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else if (strcmp(Tdestino,anteriorToken)==0)
        {
            strcpy(comando.Tdestino,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tpath[0] !='\0' && comando.Tdestino[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }  
        
    }else if(strcmp(Tmovee,comando.tipo) == 0){//igual a ->43
        if (strcmp(Tpath,anteriorToken)==0)
        {
           strcpy(comando.Tpath,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else if (strcmp(Tdestino,anteriorToken)==0)
        {
            strcpy(comando.Tdestino,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tpath[0] !='\0' && comando.Tdestino[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }  
        
    }else if(strcmp(Tfindd,comando.tipo) == 0){//igual a ->45
        if (strcmp(Tpath,anteriorToken)==0)
        {
           strcpy(comando.Tpath,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else if (strcmp(Tname,anteriorToken)==0)
        {
            strcpy(comando.Tname,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tpath[0] !='\0' && comando.Tname[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }  
        
    }else if(strcmp(Tchown,comando.tipo) == 0){//igual a ->46
        if (strcmp(Tpath,anteriorToken)==0)
        {
           strcpy(comando.Tpath,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)            
        }
        else if (strcmp(Tr,anteriorToken)==0)
        {
            comando.Tr = true;
        }
        else if (strcmp(Tusr,anteriorToken)==0)
        {
            strcpy(comando.tipo,Tusr);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino no
        if (finalLinea)
        {
            if (comando.Tpath[0] !='\0' && comando.Tusr[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }      
    }else if(strcmp(Tchgrp,comando.tipo) == 0){//igual a ->47
        if (strcmp(Tusr,anteriorToken)==0)
        {
            strcpy(comando.Tusr,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
        }
        else if (strcmp(Tgrp,anteriorToken)==0)
        {
            strcpy(comando.Tgrp,auxToken);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
        }
        else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }
        //veo si cumple todos los parametros si si lo guardo y EJECUTO EL COMANDO, sino noy
        if (finalLinea)
        {
            if (comando.Tusr[0] !='\0' && comando.Tgrp[0] !='\0')
            {
                contComandos++;
            }else{
                cout<<comando.tipo<<" error no se puede generar este comando";
                LimpiaString(comandos[contComandos].tipo);
                return -1;
            }
            
        }else{//es espacio en blanco

        }        
        
    }else if(strcmp(Tpausee,comando.tipo) == 0){//igual a ->48
        if (finalLinea)
        {
            //Ejecucion comando
            char prueba[10];
            cout<<"EN PAUSA.............................."<<endl;
            cin>>prueba;
            
            contComandos++;
        }else{
            cout<<comando.tipo<<" error no se puede generar este comando";
            LimpiaString(comandos[contComandos].tipo);
            return -1;
        }   
    }
    
    else{

    }  

    return 0;
}//VerificarParametro

void leerEntrada(char *pathArchivo){
    ifstream f;
    char dato;
    //---------contadores-------------
    int contCiclo =0;
    contComandos=0;//para cuantos comando hay en archivo inicio
    /**
     * guardara temporalmente los lexemas entrada
    */
    char auxToken[85]={'\0'};
    char anteriorToken[50]={'\0'};
    //------------Banderas--------------------
    //para signo -> , se podria hacer tirandolo a otro metodo si no fuera con bandera
    bool banderaFlecha=false; 
    bool banderaComentario=false;
    bool banderaCadena=false;

    f.open(pathArchivo);//OJO:cambia a ruta
    if(!f)
        cout << "Error abriendo el fichero" << endl;
    else
    {
        dato = f.get();

        while(! f.eof())
        {   
            //--------------salto de linea
            if (dato == '\n') // || dato == #, si # ver si hay algo guardado
            {            
                //un comentario era lo ultimo
                if (banderaComentario)
                {
                    //guarda el comentario
                    cout<<"guardo comentario:"<<auxToken<<endl;
                    //limpia los arreglos, el de TOKENS
                    LimpiaString(auxToken);
                    contCiclo=0;
                    banderaComentario= false;
                    cout<<"\n";
                }
                 //-----y para fin de linea q no es comentario, parametros,id, etc... ----------
                else{
                    if (banderaFlecha)//----Para guardar los parametros----------
                    {
                        //banderaCadena
                        if(banderaCadena)
                        {
                            //quito comillas a la direccion
                            string auxToken2 = auxToken;
                            auxToken2 = auxToken2.substr(1, auxToken2.length() - 2);
                            strcpy(auxToken,auxToken2.c_str());

                            
                            banderaCadena= false;
                            cout<<"\n";
                        }

                        VerificarParametro(anteriorToken,auxToken,true);
                        //limpia las cosas de verificar parametro,bandera flecha tamb,auxanterior tamb
                        LimpiaString(auxToken);
                        LimpiaString(anteriorToken);
                        contCiclo=0;
                        banderaFlecha=false;   
                    
                    }
                    
                    else{//Guardo token pero no guardare un parametro
                        contCiclo=VerificarTok(auxToken,contCiclo,anteriorToken,&banderaFlecha);

                    }
                    
                }
            }
            //--------------espacio en blanco  // tambien  para tabulador son 3 de estos
            else if (dato == ' ') 
            {
                //concatenamos espacio a comentarios
                if(banderaComentario){
                    auxToken[contCiclo]=dato;
                    contCiclo++;
                }
                else{ //para verificar q tipo es el auxToken

                    if (banderaFlecha)//-----para guardar los parametreos
                    {
                        if(banderaCadena)
                        {
                            //quito comillas a la direccion
                            string auxToken2 = auxToken;
                            auxToken2 = auxToken2.substr(1, auxToken2.length() - 2);
                            strcpy(auxToken,auxToken2.c_str());
                            
                            banderaCadena= false;
                            cout<<"\n";
                        }

                        VerificarParametro(anteriorToken,auxToken,false);
                        //limpia las cosas de verificar parametro,bandera flecha tamb,auxanterior tamb
                        LimpiaString(auxToken);
                        LimpiaString(anteriorToken);
                        contCiclo=0;
                        banderaFlecha=false;  
                    }else{
                        contCiclo= VerificarTok(auxToken,contCiclo,anteriorToken,&banderaFlecha);//ULIIMO:
                    }
                }

            } //fin espacio en blanco
            //-----------------tabulador
            else if (dato == '\"') //concateno hasta encontrar el otro ,guardo sin las " "
            {
                cout<<"^"; //OJO:incluir banderaCadena caso en espacio y salto linea

   
            }else{//----------------caracteres no de espacio lineas, concateno TOKEN
                int comparacion=-1;

                //ver si antes venia ->, caso ->a pegado
                //limpiamos auxToken por q antes venia ->
                comparacion = strcmp("=",auxToken);//de la libreria string para comparar
                if(comparacion == 0){//igual a ->
                    cout<<"reconoce =, caso =d pegado;"<<endl;
                    //guarda ->
                    LimpiaString(auxToken);
                    contCiclo =0;
                    banderaFlecha = true;
                }//OJO: situacion -path->  pegados no tomada en cuenta
                
                
                if (banderaComentario == false && banderaCadena == false) //OJO:agrega bandera "
                {
                    //---------empiezo concatenar # -------
                    comparacion = strcmp("#",auxToken); 
                    if (comparacion == 0)
                    {
                        banderaComentario = true;
                        cout<<"entra#,contCiclo:"<<contCiclo<<endl;
                    }
                    //OJO: situacin # en un id no tomada en cuenta o entre "" y pegado a una istruccion: path->/dis.d#hola/

                    //---------- empiezo concatenar cadena -----------
                    comparacion = strcmp("\"",auxToken);
                    if(comparacion == 0)
                    {
                        banderaCadena= true;
                        cout<<"entra:\",contCiclo:"<<contCiclo<<endl;
                        
                    }

                } 
                
   
                auxToken[contCiclo]=dato;
                contCiclo++;

            }//fin else concatenar
            
            /* else if (dato == '-')//para empezar el d-> caso pegado
                {   //cout<<"entra/";
                    auxToken[contCiclo]=dato;
                    contCiclo++;
                }
            */  
            dato = f.get();//obtengo siguiente carcter 

        } //fin while
        
        f.close();
    }
}

//--------------------mkdisk----------------------------------
int EjecutarMkdisk(){
    buscarNombre(comandos[contComandos].Tpath);
    buscaDireccion(comandos[contComandos].Tpath); 
    //cout<<"guardaDireccion:"<<guardaDireccion<<endl;
   
    crearDirectorio(guardaDireccion);//crea los dirctorios necesarios para guardar el archivo

    //---------------------------------------------------------------------------------------------
    char direccionMasArchivo[90] = {'\0'};//direccion completa
    strcpy(direccionMasArchivo,guardaDireccion);
    char slash[] = {'/'};
    strcat(direccionMasArchivo,"/");
    strcat(direccionMasArchivo,guardaNombre);
    //cout<<"direccionMasArchivo: "<<direccionMasArchivo<<endl;

    int tamaño = comandos[contComandos].Ts*1048576;//por defecto en mb
    
    ifstream archivo;

    //c
    archivo.open(direccionMasArchivo,ios::in | ios::binary);// in de entrada
    if (!archivo)//no existe
    {
        archivo.close();
        ofstream archivo_o;
        //c
        archivo_o.open(direccionMasArchivo,ios::out | ios::binary);
        
        //kylobyt = 1024 bytes
        //megabyte = 1.048.576 bytes
        //struct MBR enBlanco; //representa un registro a guardar profesor o estudiante en blanco       
       
        if (comandos[contComandos].Tu[0] == 'k')
        {
            tamaño = comandos[contComandos].Ts*1024;
        }
       
        //si quiciera escescribe 50 reistros De struct TipoStruct , tamaño:50x76=3800bytes, 76 es el tamaño un struct TipoStruct
        //si quiciera 50bytes seria solo con bytes y escribir "\0";, llamo a caracter0
        for (int i = 0; i < tamaño; i++) {
            //archivo_o.write(reinterpret_cast< const char * >(&enBlanco),sizeof(MBR));
            archivo_o.write(reinterpret_cast< const char * >(&carac0),sizeof(carac0));
        }
        archivo_o.close();

    }//fin !archivo
    else{
        //hacer cosas si ya existe por lo abri
        ErrorT("no se pudo crear el disco");
        LimpiaString(guardaNombre); 
        LimpiaString(guardaDireccion); 
        archivo.close();
    }
 //---------------------------------CREACION MBR ----------------------------------------------------------   
      //cout<<"tamaño profesor:"<<sizeof(Profesor)<<"\n";
      //----------Lleno datos --------------------
        struct MBR itrRegistro; //unico registro mbr se metera en el disco

        itrRegistro.mbr_dsk_signature = mbrRandom;
        mbrRandom++;

        time_t now = time(0); //fecha y tiempo actual segun sistema
        itrRegistro.mbr_fecha_creacion = now;

        if(strcmp(comandos[contComandos].Tf,"ff")==0 || strcmp(comandos[contComandos].Tf,"bf")==0 || strcmp(comandos[contComandos].Tf,"wf")==0){
            strcpy(itrRegistro.dsk_fit,comandos[contComandos].Tf);
        } else if(comandos[contComandos].Tf[0] == '\0') {
            strcpy(itrRegistro.dsk_fit,"ff");
        }else{
            ErrorT("el ajuste indicado no existe");
            return -1;    
        }
        
        itrRegistro.mbr_tamano = tamaño;
        //inicializo stado de las particiones del mbr----------------
        strcpy(itrRegistro.mbr_partition_1.part_status,"1");
        strcpy(itrRegistro.mbr_partition_2.part_status,"1");
        strcpy(itrRegistro.mbr_partition_3.part_status,"1");
        strcpy(itrRegistro.mbr_partition_4.part_status,"1");

        //-----------guardo mbr nuevamente----------------------------
        fstream archivoBinario;
        archivoBinario.open(direccionMasArchivo,ios::in | ios::out | ios::binary);
        if (!archivoBinario)
        {
            cout<<"error al abrir archivo en mkdisk\n";
            LimpiaString(guardaNombre); 
            LimpiaString(guardaDireccion); 
            return -1;
        }
        //busca posicion
        archivoBinario.seekp(0*sizeof(MBR));
        //escrie la info en el archivo binario
        archivoBinario.write(reinterpret_cast< const char * >(&itrRegistro),sizeof(MBR));
        archivoBinario.close();  
        cout << "Se creo disco correctamente" << endl;
        LimpiaString(guardaNombre); 
        LimpiaString(guardaDireccion); 
        return 0;             
}

void crearDirectorio(char *direccion){
    try
    {
    string aux = direccion;
    string comando = "sudo mkdir -p \'"+aux+"\'";
    //cout << comando <<endl;
    system(comando.c_str());

    buscaNombrePadre(direccion);
    aux = guardaNombrePadre;
    string comando2 = "sudo chmod -R 777 \'"+aux+"\'";//da permisos absoultos al usuario,grupo y otros, recursivamente
    //cout<<comando2<<endl;
    system(comando2.c_str());
    LimpiaString(guardaNombrePadre);
    }
    catch(const std::exception& e)
    {
        ErrorT("no se genero el directorio");
        LimpiaString(guardaNombrePadre);
    }
    
}

//---------------------Fdisk-------------------------------------
int EjecutarFdisk(){//OJO:param puede ser num particion a modificar o en los parametros 
   
   //----------OJO:deberia comprobar la direccion exacta ----------
   //llena guardarNombre----------------
    buscarNombre(comandos[contComandos].Tpath);
    buscaDireccion(comandos[contComandos].Tpath); 
    //cout<<"guardaDireccion:"<<guardaDireccion<<endl;
   
    //---------------------------------------------------------------------------------------------
    char direccionMasArchivo[90] = {'\0'};//direccion completa
    strcpy(direccionMasArchivo,guardaDireccion);
    strcat(direccionMasArchivo,"/");
    strcat(direccionMasArchivo,guardaNombre);

    
    struct Particion auxParticion;
     auxParticion.part_s  =  comandos[contComandos].Ts;
    strcpy(auxParticion.part_fit,comandos[contComandos].Tu);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)
    //direccion particion    
    strcpy(auxParticion.part_name,comandos[contComandos].Tname);//de la libreria string copia al primer param el param 2 desde 0 size(segundo)    

    //---------------Abre y lee mbr----------------------
    ifstream ArchivoBinario;
    ArchivoBinario.open(direccionMasArchivo, ios::in | ios::binary);
    if (!ArchivoBinario)
    {
        cout<<"error al abrir archivo en fdisk\n";
    }
    struct MBR itrRegistro_rb;
    //lee primer registro
    ArchivoBinario.read(reinterpret_cast< char * >(&itrRegistro_rb),sizeof(MBR));
    ArchivoBinario.close();

    //--------------------------CREAR PARTICIONES--------------------------------------
    if (strcmp(auxParticion.part_type,"p") == 0)
    {
     //creaParticionPrimaria(&itrRegistro_rb,&auxParticion);
        int result = creaParticionPrimaria(&itrRegistro_rb,&auxParticion,direccionMasArchivo);   
        if(result == -1){ ErrorT("al crear particion primaria"); return -1;}

    }else  if (strcmp(auxParticion.part_type,"e") == 0)
    {       
        if(crearParticionExtendida(&itrRegistro_rb,&auxParticion,direccionMasArchivo)  == -1)
        { ErrorT("al crear particion extendida"); return -1;}

    } else if (strcmp(auxParticion.part_type,"l") == 0)
    {
        int result = crearParticionLogica(&itrRegistro_rb,&auxParticion,direccionMasArchivo);
        if(result == -1){ ErrorT("al crear particion logica"); return -1;}

    } else if(auxParticion.part_type[0] == '\0'){
        int result = creaParticionPrimaria(&itrRegistro_rb,&auxParticion,direccionMasArchivo);   
        if(result == -1){ ErrorT("al crear particion primaria"); return -1;}
    }
    else
    {
       ErrorT("no existe este tipo de particion");
       return -1;
    }
    //----------------------------------------------------------------
     

    //---------abre  y escribe mbr nuevo-----------------------
    /*
    fstream archivoBinario;
    archivoBinario.open(direccionMasArchivo, ios::in | ios::out | ios::binary );
    if (!archivoBinario)
    {
        cout<<"error al abrir archiivo fdisk\n";
        return -1;
    }

    //busca posicion
    archivoBinario.seekp(0*sizeof(MBR));
    //escrie la info en el archivo binario
    archivoBinario.write(reinterpret_cast< const char * >(&itrRegistro_rb),sizeof(MBR));
    archivoBinario.close();
    */    
    LimpiaString(guardaNombre); 
    LimpiaString(guardaDireccion);
    return 0;
}


/**
 * @param auxParticion contiene la particion a introducir
 * @param mbr_ = masterboot
*/
int creaParticionPrimaria(struct MBR *mbr_,struct Particion *auxParticion,char *direccion){
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
    //0 activa, 1 no activa
    //---------espacio usado
    int espacioUsado = 0;
    if(strcmp(mbr_->mbr_partition_1.part_status,"0") == 0){
        espacioUsado += mbr_->mbr_partition_1.part_s;
    }else if(strcmp(mbr_->mbr_partition_2.part_status,"0") == 0){
        espacioUsado += mbr_->mbr_partition_2.part_s;
    } else if(strcmp(mbr_->mbr_partition_3.part_status,"0") == 0){
        espacioUsado += mbr_->mbr_partition_3.part_s;
    } else if(strcmp(mbr_->mbr_partition_4.part_status,"0") == 0){
        espacioUsado += mbr_->mbr_partition_4.part_s;
    }
    cout << "Espacio disponible: " << (mbr_->mbr_tamano - espacioUsado) << " Bytes" << endl;
    cout << "Espacio necesario:  " << auxParticion->part_s << " Bytes" << endl;
    //-------------
    if((mbr_->mbr_tamano - espacioUsado) >= auxParticion->part_s)
    {}
    else { cout<< "ERROR la particion a crear excede el espacio libre" << endl;return -1;}
    //if(!existeParticion(direccion,nombre)){}

    bool banderaParticion=false;//degtermina si hay particiones disponibles
    int numParticion = -1;//la particion libre
    //------------_Verifica si hay particiones disponibles  
    if(strcmp(mbr_->mbr_partition_1.part_status,"1") == 0 ){//&& mbr_->mbr_partition_1.part_s >=auxParticion->part_s
        banderaParticion = true;
        numParticion =0;
        primeraParticion = mbr_->mbr_partition_1;
    }else if(strcmp(mbr_->mbr_partition_2.part_status,"1") == 0 ){//&& mbr_->mbr_partition_2.part_s >=auxParticion->part_s
        banderaParticion = true;
        numParticion =1;
        primeraParticion = mbr_->mbr_partition_2;
    } else if(strcmp(mbr_->mbr_partition_3.part_status,"1") == 0 ){//&& mbr_->mbr_partition_3.part_s >=auxParticion->part_s
        banderaParticion = true;
        numParticion =2;
        primeraParticion = mbr_->mbr_partition_3;
    } else if(strcmp(mbr_->mbr_partition_4.part_status,"1") == 0 ){//&& mbr_->mbr_partition_4.part_s >=auxParticion->part_s
        banderaParticion = true;
        numParticion =3;
        primeraParticion = mbr_->mbr_partition_4;
    }
    //Para ERROR
    if(banderaParticion == false){cout<< "ERROR las 4 particiones estan llenas " << endl;return -1;}
    //copiar el restro queda

    if(strcmp(mbr_->dsk_fit,"ff") == 0){//FIRST FIT
        strcpy(primeraParticion.part_type,"p");
        strcpy(primeraParticion.part_fit,auxParticion->part_fit);
        //para start 
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
        //------------------buasca q particion modificar---------
        if(numParticion == 0){
            mbr_->mbr_partition_1 = primeraParticion;
        }else if(numParticion == 1){
            mbr_->mbr_partition_2 = primeraParticion;
        } else if(numParticion == 2){
            mbr_->mbr_partition_3 = primeraParticion;
        } else if(numParticion == 3){
            mbr_->mbr_partition_4 = primeraParticion;
        }

        //-----------Se guarda de nuevo el MBR en el archivo indicado------------------
        fstream archivoBinario;
        archivoBinario.open(direccion,ios::in | ios::out | ios::binary);
        if (!archivoBinario)
        {
            cout<<"error al abrir archivo crearPrimaria \n";
            return -1;
        }
        archivoBinario.seekp(0*sizeof(MBR)); 
        //escrie la info en el archivo binario
        archivoBinario.write(reinterpret_cast< const char * >(&mbr_),sizeof(MBR));
        archivoBinario.close();
        cout << "...\n" << "Particion primaria creada con exito" <<  endl;
        
    }else if(strcmp(mbr_->dsk_fit,"bf") == 0){//BEST FIT
        int bestIndex = numParticion;
        //best index
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
        if(bestIndex == 0){
            strcpy(mbr_->mbr_partition_1.part_type,"p");
            strcpy(mbr_->mbr_partition_1.part_fit,auxParticion->part_fit);
            //start
            mbr_->mbr_partition_1.part_start = sizeof(mbr_);
            mbr_->mbr_partition_1.part_s = auxParticion->part_s;
            strcpy(mbr_->mbr_partition_1.part_status,"0");  
            strcpy(mbr_->mbr_partition_1.part_name,auxParticion->part_name);  
        }else if(bestIndex == 1){
            strcpy(mbr_->mbr_partition_2.part_type,"p");
            strcpy(mbr_->mbr_partition_2.part_fit,auxParticion->part_fit);
            //start
            mbr_->mbr_partition_2.part_start = mbr_->mbr_partition_1.part_start + mbr_->mbr_partition_1.part_s;
            mbr_->mbr_partition_2.part_s = auxParticion->part_s;
            strcpy(mbr_->mbr_partition_2.part_status,"0");
            strcpy(mbr_->mbr_partition_2.part_name,auxParticion->part_name);
        } else if(bestIndex == 2){
            strcpy(mbr_->mbr_partition_3.part_type,"p");
            strcpy(mbr_->mbr_partition_3.part_fit,auxParticion->part_fit);
            //start
            mbr_->mbr_partition_3.part_start = mbr_->mbr_partition_2.part_start + mbr_->mbr_partition_2.part_s;  
            mbr_->mbr_partition_3.part_s = auxParticion->part_s;  
            strcpy(mbr_->mbr_partition_3.part_status,"0");
            strcpy(mbr_->mbr_partition_3.part_name,auxParticion->part_name);
        } else if(bestIndex == 3){
            strcpy(mbr_->mbr_partition_4.part_type,"p");
            strcpy(mbr_->mbr_partition_4.part_fit,auxParticion->part_fit);
            //start
            mbr_->mbr_partition_4.part_start = mbr_->mbr_partition_3.part_start + mbr_->mbr_partition_3.part_s;
            mbr_->mbr_partition_4.part_s = auxParticion->part_s;
            strcpy(mbr_->mbr_partition_4.part_status,"0");
            strcpy(mbr_->mbr_partition_4.part_name,auxParticion->part_name);
        }
        //Se guarda de nuevo el MBR en el archivo indicado
        fstream archivoBinario;
        archivoBinario.open(direccion,ios::in | ios::out | ios::binary);
        if (!archivoBinario)
        {
            cout<<"error al abrir archivo ,crearPrimaria\n";
            return -1;
        }
        archivoBinario.seekp(0*sizeof(MBR)); 
        //escrie la info en el archivo binario
        archivoBinario.write(reinterpret_cast< const char * >(&mbr_),sizeof(MBR));
        archivoBinario.close();
        cout << "...\n" << "Particion primaria creada con exito" <<  endl;
        
    }else if(strcmp(mbr_->dsk_fit,"wf") == 0){//WORST FIT
        int  worstIndex= numParticion;
        for(int i = 0; i < 4; i++){
            if(strcmp(ParticionesArreglo[i].part_status,"1") == 0 && ParticionesArreglo[i].part_s>=auxParticion->part_s){
                if(i != numParticion){
                    if(ParticionesArreglo[worstIndex].part_s < ParticionesArreglo[i].part_s){
                        worstIndex = i;
                        break;
                    }
                }
            }
        }
        //------------------buasca q particion modificar---------
        if(worstIndex == 0){
            strcpy(mbr_->mbr_partition_1.part_type,"p");
            strcpy(mbr_->mbr_partition_1.part_fit,auxParticion->part_fit);
            //start
            mbr_->mbr_partition_1.part_start = sizeof(mbr_);
            mbr_->mbr_partition_1.part_s = auxParticion->part_s;
            strcpy(mbr_->mbr_partition_1.part_status,"0");
            strcpy(mbr_->mbr_partition_1.part_name,auxParticion->part_name);

        }else if(worstIndex == 1){
            strcpy(mbr_->mbr_partition_2.part_type,"p");
            strcpy(mbr_->mbr_partition_2.part_fit,auxParticion->part_fit);
            //start
            mbr_->mbr_partition_2.part_start = mbr_->mbr_partition_1.part_start + mbr_->mbr_partition_1.part_s;
            mbr_->mbr_partition_2.part_s = auxParticion->part_s;
            strcpy(mbr_->mbr_partition_2.part_status,"0");
            strcpy(mbr_->mbr_partition_2.part_name,auxParticion->part_name);

        } else if(worstIndex == 2){
            strcpy(mbr_->mbr_partition_3.part_type,"p");
            strcpy(mbr_->mbr_partition_3.part_fit,auxParticion->part_fit);
            //start
            mbr_->mbr_partition_3.part_start = mbr_->mbr_partition_2.part_start + mbr_->mbr_partition_2.part_s;
            mbr_->mbr_partition_3.part_s = auxParticion->part_s;
            strcpy(mbr_->mbr_partition_3.part_status,"0");
            strcpy(mbr_->mbr_partition_3.part_name,auxParticion->part_name);

        } else if(worstIndex == 3){
            strcpy(mbr_->mbr_partition_4.part_type,"p");
            strcpy(mbr_->mbr_partition_4.part_fit,auxParticion->part_fit);
            //start
            mbr_->mbr_partition_4.part_start = mbr_->mbr_partition_3.part_start + mbr_->mbr_partition_3.part_s;
            mbr_->mbr_partition_4.part_s = auxParticion->part_s;
            strcpy(mbr_->mbr_partition_4.part_status,"0");
            strcpy(mbr_->mbr_partition_4.part_name,auxParticion->part_name);
        }
        
        //Se guarda de nuevo el MBR en el archivo indicado
        fstream archivoBinario;
        archivoBinario.open(direccion,ios::in | ios::out | ios::binary);
        if (!archivoBinario)
        {
            cout<<"error al abrir archivo, crearPrimaria\n";
            return -1;
        }
        archivoBinario.seekp(0*sizeof(MBR)); 
        //escrie la info en el archivo binario
        archivoBinario.write(reinterpret_cast< const char * >(&mbr_),sizeof(MBR));
        archivoBinario.close();
        cout << "...\n" << "Particion primaria creada con exito" <<  endl;
    }

    //------------------------------------ -------------------------
    return 0;
}

//--------------- Mount ----------------------------------------------------
int EjecutarMount(){
    int indexP = existeParticion(comandos[contComandos].Tpath,comandos[contComandos].Tname);
    if(indexP==-1){ ErrorT("no esta creada la particion"); return -1;}

    char valDireccion[90] = {'\0'};
    char valNombre[20] ={'\0'};
    strcpy(valDireccion,comandos[contComandos].Tpath);
    strcpy(valNombre,comandos[contComandos].Tname);

    //llena guardarNombre----------------
    buscarNombre(comandos[contComandos].Tpath);
    buscaDireccion(comandos[contComandos].Tpath); 
    //cout<<"guardaDireccion:"<<guardaDireccion<<endl;
   
    //---------------------------------------------------------------------------------------------
    char direccionMasArchivo[90] = {'\0'};//direccion completa
    strcpy(direccionMasArchivo,guardaDireccion);
    strcat(direccionMasArchivo,"/");
    strcat(direccionMasArchivo,guardaNombre);
    //------------direccionMasArchivo---------------------
    /*
    FILE *fp;
    if((fp = fopen(valPath,"rb")) == NULL)    
    {
        ErrorT("no puede abrirse fichero en mount");
        return -1;
    }
    
    struct MBR masterboot;
    fseek(fp,0,SEEK_SET);
    fread(&masterboot,sizeof(MBR),1,fp);
    fclose(fp);
    */
    int letra = AsignaLetra(valDireccion,valNombre);
    if(letra == -1){ ErrorT("ya esta montada la partcion"); return -1;}
    int numero = AsignaNumero(valDireccion,valNombre);
    char auxLetra[] = {static_cast<char>(letra)};
    char carnet[] = {"06"};
    char auxId[20]={'\0'};
    strcat(auxId,carnet);
    strcat(auxId,to_string(numero).c_str());
    strcat(auxId,auxLetra);

    struct ParticionMount part;
    strcpy(part.direccion,valDireccion);
    part.letra = auxLetra[0];
    strcpy(part.nombre,valNombre);
    part.numero = numero;
    strcpy(part.id,auxId);

    int insertar = insertaNodo(part);
    if(insertar == -1){ ErrorT("fallo insercion"); return -1;}
    else{cout<<"Mount con exito"<<endl;}

    mostrarMount();

    return 0;
}

int 

void ReporteConsola(){
    //puede hacer metodo comnvertir de un struct a otro registro
    // ej Struct Estudiante a TipoStruct o alrevez
 
    ifstream ArchivoBinario;
    ArchivoBinario.open("disk1.dk", ios::in | ios::binary);
    if (!ArchivoBinario)
    {
        cout<<"error al abrir archiivo\n";
    }
    struct MBR itrRegistro;
    //lee primer registro
    ArchivoBinario.read(reinterpret_cast< char * >(&itrRegistro),sizeof(MBR));
    //lee los demas registros
    while (ArchivoBinario && !ArchivoBinario.eof() )
    {
        if (itrRegistro.mbr_dsk_signature == 22)
        {
            //OJO: aqui imprimo los datos del binario pero en c/u voy cambiando sus atributos tamb
        cout<<"Los datos del MBR de entrada.script son: "<<endl;
        cout<<"mbr_tamano:"<<itrRegistro.mbr_tamano<<endl;
        char* dt = ctime(&itrRegistro.mbr_fecha_creacion); //conviete a string ctime
        cout<<"mbr_fecha_creacion:"<<dt<<endl;
        cout<<"mbr_dsk_signature:"<<itrRegistro.mbr_dsk_signature<<endl;
        }
        
        
        //lee el siguiente registro
        ArchivoBinario.read(reinterpret_cast< char * >(&itrRegistro),sizeof(MBR));
        
    }//while   
    ArchivoBinario.close(); 

}

//---------------------------------------------------------------------------------------------
/**
 * Guarda en guardaNombre el nombre en la direccion
*/
void buscarNombre(char *direccion){
    char auxNombre[20]={'\0'};
    int auxCont = 0;
    for (int i = strlen(direccion)-1; i >= 0 ; i--)
    {
        if (direccion[i] == '/')
        {
            break;
        }
        
        auxNombre[auxCont]=direccion[i];
        auxCont++;
    }
    auxCont = 0;
    for (int i = strlen(auxNombre)-1; i >= 0; i--)
    {
        guardaNombre[auxCont] = auxNombre[i];
        auxCont++;
    }
      
}

void buscaNombrePadre(char *direccion){

    for (int i = 0; i <= strlen(direccion)-1 ; i++)
    {
        if (direccion[i] == '/')
        {
            break;
        }
        
        guardaNombrePadre[i] = direccion[i];
        
    }
}

void buscaDireccion(char *direccion){
    char auxDireccion[90]={'\0'};
    int auxCont = 0;
    bool banderadireccion= false;
    for (int i = strlen(direccion)-1; i >= 0 ; i--)
    {
        if(banderadireccion == false){
            if (direccion[i] == '/')
            {
                banderadireccion = true;    
            }
        } else{
            auxDireccion[auxCont]=direccion[i];
            auxCont++;
        }  
    }
    auxCont = 0;
    for (int i = strlen(auxDireccion)-2; i >= 0; i--)
    {
        guardaDireccion[auxCont] = auxDireccion[i];
        auxCont++;
    }
}

//------------------------------------------------------------------------------------------------
void LimpiaString(char *auxtoken){
    for (int i = 0; auxtoken[i] != '\0'; i++)
    {
        auxtoken[i]='\0';
    }
}

void LimpiaComando(struct comandoDisco *comandoL){
    for (int i = 0; comandoL->tipo[i] != '\0'; i++)
    {
        comandoL->tipo[i]='\0';
    }
    comandoL->Ts=0;

    for (int i = 0; comandoL->Tf[i] != '\0'; i++)
    {
        comandoL->Tf[i]='\0';
    }
    for (int i = 0; comandoL->Tu[i] != '\0'; i++)
    {
        comandoL->Tu[i]='\0';
    }
    for (int i = 0; comandoL->Tpath[i] != '\0'; i++)
    {
        comandoL->Tpath[i]='\0';
    }
    
    for (int i = 0; comandoL->Tname[i] != '\0'; i++)
    {
        comandoL->Tname[i]='\0';
    }
    for (int i = 0; comandoL->Tid[i] != '\0'; i++)
    {
        comandoL->Tid[i]='\0';
    }
    for (int i = 0; comandoL->Truta[i] != '\0'; i++)
    {
        comandoL->Truta[i]='\0';
    }
    for (int i = 0; comandoL->Tt[i] != '\0'; i++)
    {
        comandoL->Tt[i]='\0';
    }
    for (int i = 0; comandoL->Tdelete[i] != '\0'; i++)
    {
        comandoL->Tdelete[i]='\0';
    }
    comandoL->Tadd =0;
    for (int i = 0; comandoL->Ttype[i] != '\0'; i++)
    {
        comandoL->Ttype[i]='\0';
    }
    for (int i = 0; comandoL->Tfs[i] != '\0'; i++)
    {
        comandoL->Tfs[i]='\0';
    }
    for (int i = 0; comandoL->Tusr[i] != '\0'; i++)
    {
        comandoL->Tusr[i]='\0';
    }
    for (int i = 0; comandoL->Tpass[i] != '\0'; i++)
    {
        comandoL->Tpass[i]='\0';
    }
    for (int i = 0; comandoL->Tgrp[i] != '\0'; i++)
    {
        comandoL->Tgrp[i]='\0';
    }
    comandoL->Tugo=0;
    comandoL->Tr=false;
    for (int i = 0; comandoL->Tcont[i] != '\0'; i++)
    {
        comandoL->Tcont[i]='\0';
    }
    for (int i = 0; comandoL->Tfile[i] != '\0'; i++)
    {
        comandoL->Tfile[i]='\0';
    }
    comandoL->TfileN=0;
    comandoL->Tp = false;
    for (int i = 0; comandoL->Tdestino[i] != '\0'; i++)
    {
        comandoL->Tdestino[i]='\0';
    }

}

void A_minusculas(char *cadena){
    int i=0;
    char c;
    while (cadena[i])
    {
        c=cadena[i];
        cadena[i]= tolower(c);
        i++;
    }
}



//quito crearParticionExtendida
