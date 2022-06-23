#ifndef SEGUROS_H_INCLUDED
#define SEGUROS_H_INCLUDED
#include "prototipos.h"
#include "textos_menues.h"
int menuSeguro(){
int opc;

    while(true){
        system("cls");
    textoMenuSeguros();
    cin >> opc;

    switch(opc){

    case 1:
            if(cargarSeguro()==true){
             cout << "SEGURO CARGADO CON EXITO." << endl;
             }else{
             cout << "No se pudo cargar el seguro. " << endl;
             }
             system("pause");
        break;

    case 2:
        MostrarSeguroporPatente();
        system("pause");
        break;

    case 3:
            mostrarSeguro();
        break;

    case 4:
        if(modifica_patente_seguro()==true){

            cout << "FECHA MODIFICADA CON EXITO. " << endl;
        }else{

        cout << "No se pudo modificar la fecha. " <<endl;}

        system("pause");
        break;

    case 5:
            if(bajalogicaSeguros()==true){

                cout << "SEGURO DADO DE BAJA CON EXITO." << endl;
            }else{

            cout << "No se pudo dar de baja el seguro. " << endl;
            }

            system("pause");
        break;

    case 0:
        return 0;
        break;
        }

    }

}

#endif // SEGUROS_H_INCLUDED
