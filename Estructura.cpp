#pragma once
#include <ctime>//para fecha y hora, para random tambien
//#include <time.h>//para el random


struct Particion{
    char part_status[15]={'\0'};//Indica si la partición está activa(0) o no(1)
    char part_type[15]={'\0'};//Indica el tipo de partición, primaria o extendida. Tendrá los valores P o E
    char part_fit[15]={'\0'};//Tipo de ajuste de la partición. Tendrá los valores B (Best), F (First) o W (worst)
    int part_start = -1;//Indica en qué byte del disco inicia la partición
    int part_s = 0;//Contiene el tamaño total de la partición en bytes
    char part_name[16]={'\0'};//Nombre de la partición
};

struct MBR{
    int mbr_tamano=0;//tamaño total del disco en bytes
    // var time
    time_t  mbr_fecha_creacion;//Fecha y hora de creación del disco
    int mbr_dsk_signature=0;//Número random, que identifica de forma única a cada disco
    char dsk_fit[15]={'\0'};//Tipo de ajuste de la partición. Tendrá los valores B (Best), F (First) o W (worst)

    struct Particion mbr_partition_1;
    struct Particion mbr_partition_2;
    struct Particion mbr_partition_3;
    struct Particion mbr_partition_4;
};

struct EBR{
    char part_status[15]={'\0'};//Indica si la partición está activa(0) o no(1)
    char part_fit[15]={'\0'};//Tipo de ajuste de la partición. Tendrá los valores B (Best), F(First) o W (worst)
    int part_start = 0;//Indica en qué byte del disco inicia la partición
    int part_s = 0;//Contiene el tamaño total de la partición en bytes.
    int part_next= 0;//Byte en el que está el próximo EBR. -1 si no hay siguiente
    char part_name[16]={'\0'};//Nombre de la partición
};
