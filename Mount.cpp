#pragma once
#include <iostream>
#include <string.h>
#include "Estructura.cpp"

using namespace std;

int AsignaLetra(char *direccion,char *nombre);
int AsignaNumero(char *direccion,char *nombre);
int buscaParticionMount(char *direccion,char *nombre);
/* Funcion que retorna el indice de la particion o -1
 * @param direccion: direccion del disco
 * @param nombre: nombre de la particion
 * @return i = si lo encuentra | -1 = si no lo encuentra
*/
int buscaParticionMountId(char *direccion,char *nombre);
/** Muestra las particiones montadas
*/
int mostrarMount();
/** Metodo para insertar al final de la lista
 * @param Particion nuevo: El nodo a insertar
*/
int insertaNodo(struct ParticionMount particion);

/** Metodo para insertar al final de la lista
 * @param return:-1 si hay error al insertar y 0 si se incerto correctamente
*/
int eliminarNodo(char *id);

//----------------------------------------------------------------
/** Funcion para verificar que letra asignarle a una Particion Mount
 * @param char *direccion: Ruta del disco
 * @param char *nombre: nombre de la particion
 * @return -1 = ya esta montada | # = letra
*/
int AsignaLetra(char *direccion, char *nombre){
    int retorno = 'a';
    for (int i = 24;   i >= 0 ; i--)
    {   
        if(strcmp(direccion, ParticionesMount[i].direccion) == 0 && strcmp(nombre,ParticionesMount[i].nombre) == 0)
        {
            return -1;
        } else
        {
            if(strcmp(direccion, ParticionesMount[i].direccion))
            {
                return ParticionesMount[i].letra;
            }else if(i == 0){
                return retorno;
            }
        }
    }
    
}
/** Funcion para verificar que numero asignarle al id de una ParticionMount
 * @param  direccion: nombre de la particion
 * @return nombre = numero a asignar
*/
int AsignaNumero(char *direccion,char *nombre){
    
    for (int i =24; i >= 0; i--)
    {
        if ((ParticionesMount[i].direccion == direccion))
        {
            return ParticionesMount[i].numero+1;
        }
        else if (i == 0)
        {
            return 1;
        }
        
    }
    
}
/* Funcion que retorna un  para verificar si existe un nodo
 * @param direccion: direccion del disco
 * @param nombre: nombre de la particion
 * @return 0 = si lo encuentra | -1 = si no lo encuentra
*/
int buscaParticionMount(char *direccion,char *nombre){
    for (int i =24; i >= 0; i--){
        if(ParticionesMount[i].direccion == direccion &&
           ParticionesMount[i].nombre == nombre)
        {
            return 0;
        }
    }
    return -1;
}

int buscaParticionMountId(char *id){
    for (int i =0; i < 25; i++){
        if(ParticionesMount[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

int insertaNodo(struct ParticionMount particion)
{
    for (int i = 0; i < 25; i++)
    {
        if(ParticionesMount[i].id[0] == '\0')
        {
            ParticionesMount[i] = particion;
            return 0;
        }
    }
    return -1;
    
}

int eliminarNodo(char *id){
    for (int i = 0;i <= 24;i++)
    {
        if(strcmp(ParticionesMount[i].id,id)==0)
        {
            struct ParticionMount p;//creo funciona
            ParticionesMount[i] = p;//borrada
            //corro todo
            if(i != 24)//no es el ultimo
            {
                if(ParticionesMount[i+1].id[0] == '\0'){
                    for (int j = i; j > 24; j++)//puede optimizar este
                    {
                        ParticionesMount[i]=ParticionesMount[i+1];
                    }
                }
            }//fin 24
            return 0;
        }
    }
    return -1;

}

int mostrarMount()
{
    cout<< "---------------------------------" << endl;
    cout<< "|       Particiones montadas    |" << endl;
    cout<< "---------------------------------" << endl;

    for (int i = 0; i<25 || ParticionesMount[i].id[0] != '\0' ; i++)
    {
        cout<<"nombre:"<<ParticionesMount[i].nombre<<" id:"<<ParticionesMount[i].id<<endl;
    }
    

}