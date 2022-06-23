#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <conio.h>

using namespace std;

#include "rlutil.h"
#include "textos_menues.h"
#include "funciones.h"
#include "prototipos.h"

#include "classconductor.h"
#include "classvehiculos.h"
#include "classtarifas.h"
#include "classseguros.h"
#include "classviajes.h"


#include "classfecha.h"
#include "menuconductores.h"
#include "menuviajes.h"
#include "menuvehiculos.h"
#include "menutarifas.h"
#include "menuseguros.h"

int main(){
    int opc;

    while(true){
    textoMenuMain();
    cin >>opc;

        switch(opc){
        case 1:
            menuConductores();
            break;
        case 2:
            menuViajes();
            break;
        case 3:
            menuVehiculos();
            break;
        case 4:
            menuTarifas();
            break;
        case 5:
            menuSeguro();
            break;
        case 0:
            return 0;
            break;
        }
    }
    return 0;
}
