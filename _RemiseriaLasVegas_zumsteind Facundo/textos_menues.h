#ifndef TEXTOS_MENUES_H_INCLUDED
#define TEXTOS_MENUES_H_INCLUDED

void textoMenuMain();
void textoMenuConductores();
void textoMenuSeguros();
void textoMenuViajes();
void textoMenuTarifas();
void textoMenuVehiculos();




void textoMenuMain(){
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(52,3);
    cout << "REMISERIA LAS VEGAS" << endl << endl;
    rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(55,5);
    cout << "MENU PRINCIPAL" << endl << endl;
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(47,7);
    cout << "1)_ MENU CONDUCTORES " << endl;
    rlutil::locate(47,8);
    cout << "2)_ MENU VIAJES" << endl;
    rlutil::locate(47,9);
    cout << "3)_ MENU VEHICULOS " << endl;
    rlutil::locate(47,10);
    cout << "4)_ TARIFAS " << endl;
    rlutil::locate(47,11);
    cout << "5)_ SEGURO AUTOS " << endl<<endl;

    rlutil::locate(47,13);
    cout << "0)_  FIN DEL PROGRAMA " << endl << endl;

rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(51,15);
    cout << "Seleccione una opcion" << endl;
rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::locate(46,4);
    cout << (char) 201;
    rlutil::locate(76,4);
    cout << (char) 187;

    rlutil::locate(46,16);
    cout << (char) 200;
    rlutil::locate(76,16);
    cout << (char) 188;

    for(int i=5;i<=15;i++){
        rlutil::locate(46,i);
        cout << (char) 186;
    }

    for(int i=5;i<=15;i++){
        rlutil::locate(76,i);
        cout << (char) 186;
    }
    for(int i=0;i<=28;i++){
        rlutil::locate(47+i,4);
        cout << (char) 205;
    }

    for(int i=0;i<=28;i++){
        rlutil::locate(47+i,6);
        cout << (char) 205;
    }
    for(int i=0;i<=28;i++){
        rlutil::locate(47+i,12);
        cout << (char) 205;
    }
    for(int i=0;i<=28;i++){
        rlutil::locate(47+i,16);
        cout << (char) 205;
    }

    rlutil::locate(60,18);
}

void textoMenuConductores(){
   rlutil::setBackgroundColor(rlutil::DARKGREY);
    rlutil::cls();
    rlutil::setColor(rlutil::BLUE);
    rlutil::locate(55,5);
    cout << " MENU CONDUCTORES" << endl << endl;
    rlutil::setColor(rlutil::LIGHTCYAN);
    rlutil::locate(47,7);
    cout << "1)_ AGREGAR CONDUCTOR" << endl;
    rlutil::locate(47,8);
    cout << "2)_ LISTAR CONDUCTOR POR DNI" << endl;
    rlutil::locate(47,9);
    cout << "3)_ LISTAR TODOS LOS CONDUCTORES" << endl;
    rlutil::locate(47,10);
    cout << "4)_ BAJA CONDUCTOR" << endl;
    rlutil::locate(47,13);
    cout << "0)_ VOLVER AL MENU PRINCIPAL" << endl << endl;

 rlutil::setColor(rlutil::BLUE);
for(int i=0;i<=31;i++){
    rlutil::locate(47+i,6);
    cout << (char) 205;
}
for(int i=0;i<=31;i++){
    rlutil::locate(47+i,12);
    cout << (char) 205;
}
for(int i=0;i<=31;i++){
    rlutil::locate(47+i,16);
    cout << (char) 205;
}
 rlutil::setColor(rlutil::LIGHTCYAN);
   rlutil::locate(52,15);
    cout << "Seleccione una opcion" << endl;
    rlutil::locate(60,18);

}

void textoMenuSeguros(){
    rlutil::setBackgroundColor(rlutil::GREY);
    rlutil::cls();
    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(57,5);
    cout << "MENU SEGUROS" << endl<<endl;
      rlutil::setColor(rlutil::BROWN);
    rlutil::locate(47,7);
    cout << "1)_ AGREGAR SEGURO " << endl;
    rlutil::locate(47,8);
    cout << "2)_ LISTAR SEGURO POR PATENTE" << endl;
    rlutil::locate(47,9);
    cout << "3)_ MOSTRAR TODOS LOS SEGUROS" << endl;
    rlutil::locate(47,10);
    cout << "4)_ MODIFICAR FECHA DE VIGENCIA" <<endl;
    rlutil::locate(47,11);
    cout << "POR N" <<(char) 167 << " DE PATENTE" << endl;
    rlutil::locate(47,12);
    cout << "5)_ BAJA SEGURO POR N" <<(char) 167 << " PATENTE" << endl<<endl;
    rlutil::locate(47,13);
    cout << "0)_ VOLVER AL MENU PRINCIPAL" << endl << endl;
rlutil::setColor(rlutil::LIGHTRED);
for(int i=0;i<=31;i++){
    rlutil::locate(47+i,6);
    cout << (char) 205;
}
for(int i=0;i<=31;i++){
    rlutil::locate(47+i,12);
    cout << (char) 205;
}
for(int i=0;i<=31;i++){
    rlutil::locate(47+i,16);
    cout << (char) 205;
}
rlutil::setColor(rlutil::BROWN);
   rlutil::locate(52,15);
    cout << "Seleccione una opcion" << endl;
    rlutil::locate(62,18);
}

void textoMenuVehiculos(){
    rlutil::setBackgroundColor(rlutil::GREY);
    rlutil::cls();
     rlutil::setColor(rlutil::MAGENTA);
    rlutil::locate(55,5);
    cout << "MENU VEHICULOS" << endl<<endl;
      rlutil::setColor(rlutil::CYAN);
    rlutil::locate(47,7);
    cout << "1)_ AGREGAR VEHICULO" << endl;
    rlutil::locate(47,8);
    cout << "2)_ LISTAR VEHICULO POR PATENTE" << endl;
    rlutil::locate(47,9);
    cout << "3)_ LISTAR TODOS LOS VEHICULOS " << endl;
    rlutil::locate(47,10);
    cout << "4)_ BAJA VEHICULO"<< endl;
    rlutil::locate(47,13);
    cout << "0)_ VOLVER AL MENU PRINCIPAL" << endl << endl;
rlutil::setColor(rlutil::MAGENTA);
for(int i=0;i<=30;i++){
    rlutil::locate(47+i,6);
    cout << (char) 205;
}
for(int i=0;i<=30;i++){
    rlutil::locate(47+i,12);
    cout << (char) 205;
}
for(int i=0;i<=30;i++){
    rlutil::locate(47+i,16);
    cout << (char) 205;
}
  rlutil::setColor(rlutil::CYAN);
    rlutil::locate(52,15);
    cout << "Seleccione una opcion" << endl;
    rlutil::locate(62,18);

}

void textoMenuTarifas(){
    rlutil::setBackgroundColor(rlutil::GREY);
    rlutil::cls();
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(57,5);
    cout << "MENU TARIFAS" << endl<<endl;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::locate(47,7);
    cout << "1)_ LISTAR TARIFA POR N" <<(char) 167 << " TARIFA" << endl;
    rlutil::locate(47,8);
    cout << "2)_ LISTAR TODAS LAS TARIFAS " << endl;
    rlutil::locate(47,9);
    cout << "3)_ MODIFICAR PRECIO POR KM"<<endl;
    rlutil::locate(47,10);
    cout << "POR N" <<(char) 167 << " DE TARIFA " << endl;
    //rlutil::locate(47,11);
   // cout << "4)_ baja tarifa " << endl<<endl;
    //rlutil::locate(47,12);
   /// cout << "5)_ BAJA DE TARIFA" << endl<<endl;
    rlutil::locate(47,13);
    cout << "0)_ VOLVER AL MENU PRINCIPAL" << endl << endl;
 rlutil::setColor(rlutil::CYAN);
for(int i=0;i<=30;i++){
    rlutil::locate(47+i,6);
    cout << (char) 205;
}
for(int i=0;i<=30;i++){
    rlutil::locate(47+i,12);
    cout << (char) 205;
}
for(int i=0;i<=30;i++){
    rlutil::locate(47+i,16);
    cout << (char) 205;
}
 rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::locate(52,15);
    cout << "Seleccione una opcion" << endl;
    rlutil::locate(62,18);
}


void textoMenuViajes(){
    rlutil::setBackgroundColor(rlutil::DARKGREY);
    rlutil::cls();
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(57,5);
    cout << "MENU VIAJES" << endl<<endl;
    rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(47,7);
    cout << "1)_ AGREGAR VIAJE" << endl;
    rlutil::locate(47,8);
    cout << "2)_ LISTAR VIAJE POR N" <<(char) 167 << " DE VIAJE" << endl;
    rlutil::locate(47,9);
    cout << "3)_ LISTAR VIAJES POR"<<endl;
    rlutil::locate(47,10);
    cout << "DNI CONDUCTORES" << endl;
    rlutil::locate(47,11);
    cout << "4)_ LISTAR TODOS LOS VIAJES " << endl<<endl;
    rlutil::locate(47,12);
    cout << "5)_ BAJA VIAJE POR N" <<(char) 167 << " VIAJE " << endl<<endl;
    rlutil::locate(47,13);
    cout << "0)_ VOLVER AL MENU PRINCIPAL" << endl << endl;
rlutil::setColor(rlutil::YELLOW);
    for(int i=0;i<=30;i++){
    rlutil::locate(47+i,6);
    cout << (char) 205;
}
for(int i=0;i<=30;i++){
    rlutil::locate(47+i,12);
    cout << (char) 205;
}
for(int i=0;i<=30;i++){
    rlutil::locate(47+i,16);
    cout << (char) 205;
}
rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(52,15);
    cout << "Seleccione una opcion" << endl;
    rlutil::locate(62,18);
}



#endif // TEXTOS_MENUES_H_INCLUDED
