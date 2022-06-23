#ifndef MENUTARIFAS_H_INCLUDED
#define MENUTARIFAS_H_INCLUDED
#include "prototipos.h"
#include "textos_menues.h"

///La remiseria ya tiene turnos con horarios predeterminador, asumiendo que con mayor cantidad de km se le hace un descuento en viaje.
int menuTarifas(){
    int opc;

    while(true){
    textoMenuTarifas();
    cin >>opc;

    switch(opc){
    case 1:
        system("cls");
        MostrarporNumeroDeTarifa();
        system("pause");
        break;

    case 2:
        system("cls");
        mostrarTarifa();
        system("pause");
        break;

    case 3:
        system("cls");
        modificarprecio();
        system("pause");
        break;

    case 4:
        system("cls");
        if(bajalogicaTarifa()==true)cout<<"BAJA REALIZADA."<<endl;
        system("pause");
        break;

    case 0:
        return 0;
        break;
        }

    }

}
#endif // MENUTARIFAS_H_INCLUDED
