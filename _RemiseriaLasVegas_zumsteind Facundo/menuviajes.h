#ifndef MENUVIAJES_H_INCLUDED
#define MENUVIAJES_H_INCLUDED
#include "prototipos.h"
#include "textos_menues.h"

int menuViajes(){
    int opc;

    while(true){
    textoMenuViajes();
    cin >>opc;

    switch(opc){

    case 1:
        system("cls");
        if(cargarViajes()==true){
                cout << "VIAJE CARGADO CON EXITO."<< endl;
        }else cout<<"no se pudo cargar Viaje. ";
        system("pause");
        break;

    case 2:
        system("cls");
        MostrarporNumeroDeViaje();
        system("pause");
        break;

    case 3:
        system("cls");
        if(MostrarporD()==true){
            cout << "VIAJE POR DNI CONDUCTOR LISTADO CON EXITO." << endl;
        }else{
        cout << "No se pudo mostrar el viaje por DNI conductor." << endl;}
        system("pause");
        break;
    case 4:
        system("cls");
        mostrarViajes();
        system("pause");
        break;

    case 5:
        system("cls");
        if(bajalogicaViajes()==true){
                cout<<"VIAJE DADO DE BAJA" << endl;}
                else{
                    cout << "No se pudo dar de baja el viaje." << endl;
                }
        system("pause");
        break;

    case 0:
        return 0;
        break;
        }

    }

}

#endif // MENUVIAJES_H_INCLUDED
