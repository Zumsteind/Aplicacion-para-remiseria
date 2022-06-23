#ifndef CLASSVEHICULOS_H_INCLUDED
#define CLASSVEHICULOS_H_INCLUDED

#include "prototipos.h"
///la validacion de agregar un vehiculo solo esta por patente para no ingresar dos veces el mismo vehiculo,
///pero te deja agregar dos veces el mismo dni por si el conductor cambia de vehiculo.201
class Autos{
private:
	int DNI_Cond;
	char Modelo[25];
	char Marca[25];
	float kilometraje;
	char Patente[8];
	int NumeroPoliza;
    bool Estado;

public:
    //gets()                                                                                                                                                                                    - Felipe
    int getDNIConductor(){return DNI_Cond;}
    char *getModeloAuto(){return Modelo;}
    char *getMarca(){return Marca;}
    float getKilometraje(){return kilometraje;}
    char *getPatente(){return Patente;}
    int getNumeroPoliza(){return NumeroPoliza;}
    bool getEstadoAutos(){return Estado;}

    //sets()
    void setDNIConductor(int DNIC){DNI_Cond = DNIC;}
    void setModeloAuto(const char *auto_model){strcpy(Modelo, auto_model);}
    void setMarcaAuto(const char *auto_marca){strcpy(Marca, auto_marca);}
    void setKilometraje(float auto_km){kilometraje = auto_km;}
    void setPatenteAutos(const char *auto_patente){strcpy(Patente, auto_patente);}
    void setNumeroPoliza(int num_poliz){NumeroPoliza = num_poliz;}
    void setEstadoAutos(bool state_autos){Estado = state_autos;}


	bool Cargar();
	bool Mostrar();

	// archivos

    bool grabarEnDisco(){
        FILE *pVe;
        bool grabo;
        pVe=fopen("Vehiculos.dat","ab");
        if(pVe==NULL){
            return false;
        }
        grabo=fwrite(this,sizeof *this,1,pVe);
        fclose(pVe);
        return grabo;
        }

    bool leerDeDisco(int pos){
        FILE *pVe;
        bool leyo;
        pVe=fopen("Vehiculos.dat", "rb");
        if(pVe==NULL){
            return false;
        }
        fseek(pVe,pos*sizeof *this,0);
        leyo=fread(this,sizeof *this,1,pVe);
        fclose(pVe);
        return leyo;
        }

    bool leerDeBu(int pos){
        FILE *pVe;
        bool leyo;
        pVe=fopen("Vehiculos.bkp", "rb");
        if(pVe==NULL){
            return false;
        }
        fseek(pVe,pos*sizeof *this,0);
        leyo=fread(this,sizeof *this,1,pVe);
        fclose(pVe);
        return leyo;
        }

    bool modificarendisco(int pos){
        FILE *pVe;
        bool leyo;
        pVe=fopen("Vehiculos.dat", "rb+");
        if(pVe==NULL){
            return false;
        }
        fseek(pVe,pos*sizeof *this,0);
        leyo=fwrite(this,sizeof *this,1,pVe);
        fclose(pVe);
        return leyo;
        }
};

int buscarPatente(char n[30]){
    Autos reg;
    int pos =0;
    while(reg.leerDeDisco(pos)){
        if(strcmp(reg.getPatente(),n)==0){
            return pos;
        }
        pos++;
    }
    return -1;
}

bool Autos::Cargar(){
    cout<<"***************AGREGAR VEHICULO**************"<<endl;
    cout<<"Ingrese el DNI del conductor: ";
    cin>>DNI_Cond;
    cout<<"Ingrese la marca y el modelo del vehiculo a continuacion"<<endl;
    cout<<"Marca: ";
    cargarCadena(Marca,25);
    cout<<endl<<"Modelo: ";
    cargarCadena(Modelo,25);
    cout<<"Ingrese el Kilometraje del vehiculo: ";
    cin>>kilometraje;
    cout<<"Ingrese la patente del vehiculo: ";
    cargarCadena(Patente,8);
    if(buscarPatente(Patente)!=-1){
           cout<<endl<<"PATENTE YA SE ENCUENTRA REGISTRADA EN SISTEMA"<<endl;
            Estado = false;
            return Estado;}
    cout<<endl<<"Ingrese el numero de poliza: ";
    cin>>NumeroPoliza;
    Estado=true;
    return Estado;
}

bool cargarVehiculos(){
    Autos aux;
    if(aux.Cargar()==true){

    if(aux.grabarEnDisco()==true){
        cout<<endl<<endl<<"REGISTRO AGREGADO.";
        return true;
        system("pause>nul");
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO";
    }
    cout<<endl;
    }
        return false;

}

bool Autos::Mostrar(){
    cout<<"*****************VEHICULO/s*********************"<<endl<<endl;
    cout<<"Automovil:  "<<Marca<<" "<<Modelo<<endl;
    cout<<"Patente: "<<Patente<<endl;
    cout<<"Kilometraje actual: "<<kilometraje<<" KM"<<endl;
    cout<<"DNI del conductor asociado: "<<DNI_Cond<<endl;
    cout<<"Numero de poliza: "<<NumeroPoliza<<endl;
    cout<<"Estado: ";
    if(Estado==true){
    cout<<"vehiculo habilitado";
    return true;
    }else{
    cout<<"vehiculo deshabilidado";
    return false;
    }
}

void mostrarvehiculo(){
    Autos reg;
    int pos=0;

    while(reg.leerDeDisco(pos++)){
            if(reg.getEstadoAutos()==true){
                reg.Mostrar();
                cout<<endl;
            }
    }

system("pause>nul");
}

void MostrarporPatente(){
    system("cls");
    int pos;
    char dnic[8];
        Autos reg;
    cout<<"INGRESE PATENTE DE VEHICULO A MOSTRAR: "<<"\t";
                cargarCadena(dnic,8);
                pos=buscarPatente(dnic);
                if(pos>=0){
                    cout<<endl<<endl;
                    reg.leerDeDisco(pos);
                    if(reg.getEstadoAutos()==true){
                    reg.Mostrar();

               }else cout<<"EL VEHICULO FUE BORRADO DE LA BASE DE DATOS.";
                }else{
                    cout<<"NO EXISTE ESE VEHICULO EN LA BASE DE DATOS.";
                }
                system("pause>nul");
}

bool bajalogicaVehiculos(){
    system("cls");
    int pos;
    char DNIC[8];
    bool modifico;
        Autos reg;
        cout<<endl<<"************BAJA DE VEHICULO**********"<<endl<<endl;
        cout<<"INGRESE EL NUMERO DE PATENTE A dar de baja: "<<"\t";
                cargarCadena(DNIC,8);
             //  system("cls");
                pos=buscarPatente(DNIC);
                if(pos==-1){
                        cout<<"NO EXISTE EL NUMERO DE PATENTE ";
                return false;
                }else{
                reg.leerDeDisco(pos);
                reg.setEstadoAutos(false);
                modifico=reg.modificarendisco(pos);
                return modifico;
                }

}

#endif // CLASSVEHICULOS_H_INCLUDED
