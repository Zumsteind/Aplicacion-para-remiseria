#ifndef MENUCONDUCTORES_H_INCLUDED
#define MENUCONDUCTORES_H_INCLUDED
#include "prototipos.h"
#include "textos_menues.h"

int menuConductores(){
    int opc;
    while(true){
    textoMenuConductores();
    cin >>opc;

    switch(opc){

    case 1:
        system ("cls");

        if(cargarConductor()==true){
            cout << "Conductor cargado correctamente." << endl;
            }else{
                cout<<"NO SE PUDO AGREGAR CONDUCTOR"<<endl;
                system("pause>nul");
            }
                system ("pause");
        break;
    case 2:
        system ("cls");
        MostrarporDni();
        system ("pause");
        break;

    case 3:
        system("cls");
        mostrarConductores();
        system ("pause");
        break;

    case 4:
        system("cls");
        if(bajalogicaConductores()==true){
            cout << "BAJA LOGICA REALIZADA CON EXITO" << endl;
        }else{
        cout << "No se pudo realizar la baja logica. " << endl;
        }
        system("pause");
        break;

    case 0:
        return 0;
    break;
        }

    }

}

#endif // MENUCONDUCTORES_H_INCLUDED
