/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string.h>

using namespace std;

struct Empleados
{
    char id[10]={'\0'};
    char nombre[60];
}empleadoX[1];

int main()
{
    Empleados empleado;
    char idd[21]={'\0'};
    char cad[15]={'\0'};
    int p = 33223;
    int k = 32;
    char ch = '/';
    strcpy(cad,"bola_num_12");
    cout<<"tamaño cad :"<<strlen(cad)<<endl;
    if (strcmp(cad,"Bola")==0)
    {
        //cout<<"se comparo bien"<<endl;
    }
    strcpy(cad,"perro22");
    cout<<"tamaño cad :"<<strlen(cad)<<endl;
    cout<<cad<<endl;
    cout<<cad[9]<<endl;
    if (ch == '/')
    {
                cout<<"se comparo bien: /"<<endl;
    }
    
    
    strcpy(empleado.id,"holaaaa");
    cout<<"tamaño:"<<strlen(empleado.id)<<endl<<endl;
    char Ingresoexce[50]={'\0'};
    std::cin.getline(Ingresoexce,sizeof(Ingresoexce),'\n');
    cout<<Ingresoexce<<endl;
    
    FILE *fp;
    if((fp = fopen("perro/disk1.disk","a+b")))
        fclose(fp);
    else
        cout << "Error al crear el archivo" << endl;

    return 0;
}
