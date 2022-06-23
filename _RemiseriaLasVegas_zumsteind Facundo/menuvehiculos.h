#ifndef MENUVEHICULOS_H_INCLUDED
#define MENUVEHICULOS_H_INCLUDED
#include "prototipos.h"
#include "textos_menues.h"
int menuVehiculos(){
    int opc;

    while(true){
        system("cls");

   textoMenuVehiculos();
    cin >>opc;

    switch(opc){

    case 1:
        system("cls");
        if(cargarVehiculos()==true){
            cout << "VEHICULO CARGADO CON EXITO." <<endl;
        }else{
        cout << "No se pudo cargar el vehiculo. Intente nuevamente" << endl;
        }
        system("pause");
        break;

    case 2:
        system("cls");
        MostrarporPatente();
        system("pause");
        break;

    case 3:
        system("cls");
        mostrarvehiculo();
        system("pause");
        break;

    case 4:
        system("cls");
        if(bajalogicaVehiculos()==true){
            cout<<endl<<"VEHICULO DADO DE BAJA"<<endl;}
        else{
            cout << "No se pudo dar de baja el vehiculo." << endl;
            }
        system("pause");
        break;

    case 0:
        return 0;
        break;
        }

    }

}


#endif // MENUVEHICULOS_H_INCLUDED
