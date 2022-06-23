#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
/// PROTOTIPOS DE FUNCIONES

/// MENUES
int menuConductores();
int menuViajes();
int menuVehiculos();
int menuTarifas();
int menuSeguros();

/// GENERALES
int autoincrementar();

/// CONDUCTORES
void mostrarConductores();
int buscarDni(int);
void MostrarporDni();
bool bajalogicaConductores();

/// TARIFAS
bool bajalogicaTarifa();
int buscarIdDeTarifa();
void MostrarporNumeroDeTarifa();
void modificarprecio();

/// SEGUROS
bool cargarSeguro();
void mostrarSeguro();
void MostrarSeguroporPatente();
bool modificar_patente_seguro();
int buscar_patseg(char *);
bool bajalogicaConductores();

/// VIAJES
void mostrarvehiculo();
bool bajalogicaViajes();
bool cargarViajes();
void MostrarporNumeroDeViaje();
bool MostrarporD();
bool mostrarViajes();


#endif // PROTOTIPOS_H_INCLUDED
