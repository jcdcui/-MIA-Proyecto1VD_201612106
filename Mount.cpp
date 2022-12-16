#pragma oncei < count

#include <string.h>
#include "Estructura.cpp"

int AsignaLetra(char *direccion,char *nombre);
int AsignaNumero(char *direccion,char *nombre);
int buscaParticionMount(char *direccion,char *nombre);

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
/* Funcion que retorna un booleano para verificar si existe un nodo
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