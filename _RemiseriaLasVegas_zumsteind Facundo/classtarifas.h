#ifndef CLASSTARIFAS_H_INCLUDED
#define CLASSTARIFAS_H_INCLUDED
#include "prototipos.h"

class Tarifas{
private:
    int idtarifa;
    int horainicio;
    int horafin;
    float kilometrajemaximo;
    float precio_km;
    bool Estado;

public:
    //gets
    int getIDTarifa(){return idtarifa;}
    int getHoraInicio(){return horainicio;}
    int getHoraFin(){return horafin;}
    int getPrecioporKM(){return precio_km;}
    float getKilometrajeMaximo(){return kilometrajemaximo;}
    bool getEstadoTarifa(){return Estado;}
    // sets
    void setIDTarifa(int id_t){id_t = idtarifa;}
    void setHoraInicio(int h_inicio){h_inicio = horainicio;}
    void setHoraFin(int h_fin){h_fin = horafin;}
    void setPrecioporKM(int precioPKM){precio_km = precioPKM;}
    void setKilometrajeMaximo(float tarifa_km){kilometrajemaximo = tarifa_km;}
    void setEstadoTarifa(bool state){Estado = state;}

    bool Cargar();
	bool Mostrar();

	/// archivos

        bool grabarEnDisco(){
        FILE *pArt;
        bool grabo;
        pArt=fopen("tarifas.dat","ab");
        if(pArt==NULL){
            return false;
        }
        grabo=fwrite(this,sizeof *this,1,pArt);
        fclose(pArt);
        return grabo;
        }

        bool leerDeDisco(int pos){
        FILE *pArt;
        bool leyo;
        pArt=fopen("tarifas.dat", "rb");
        if(pArt==NULL){
            return false;
        }
        fseek(pArt,pos*sizeof *this,0);
        leyo=fread(this,sizeof *this,1,pArt);
        fclose(pArt);
        return leyo;
        }

        bool leerDeBu(int pos){
        FILE *pArt;
        bool leyo;
        pArt=fopen("tarifas.bkp", "rb");
        if(pArt==NULL){
            return false;
        }
        fseek(pArt,pos*sizeof *this,0);
        leyo=fread(this,sizeof *this,1,pArt);
        fclose(pArt);
        return leyo;
        }

        bool modificarendisco(int pos){
        FILE *pArt;
        bool leyo;
        pArt=fopen("tarifas.dat", "rb+");
        if(pArt==NULL){
            return false;
        }
        fseek(pArt,pos*sizeof *this,0);
        leyo=fwrite(this,sizeof *this,1,pArt);
        fclose(pArt);
        return leyo;
        }


};

int buscarIdDeTarifa(int n){
    Tarifas reg;
    int pos =0;
    while(reg.leerDeDisco(pos)){

        if(reg.getIDTarifa()==n){
            return pos;
        }
        pos++;
    }
    return -1;
}

bool Tarifas::Cargar(){
    cout<<"Introducir ID de la tarifa: ";
    cin>>idtarifa;
    if(buscarIdDeTarifa(idtarifa)!=-1)return false;
    cout<<"Ingresar la horarios del viaje: "<<endl;
    cout<<"Inicio: ";
    cin>>horainicio;
    cout<<"Fin: ";
    cin>>horafin;
    cout<<"Ingresar km minimo para obtener precio descuento: ";
    cin>>kilometrajemaximo;

    cout<<"Precio por KM: ";
    cin>>precio_km;
    Estado=true;
    return true;
}

bool cargarTarifa(){
    Tarifas aux;
    if(aux.Cargar()==true){

        if(aux.grabarEnDisco()==true){
            cout<<endl<<endl<<"REGISTRO AGREGADO.";
            system("pause>nul");
            return true;
            }
        }else{
            cout<<"NO SE PUDO AGREGAR EL REGISTRO";
            system("pause");
            }
    cout<<endl;
    return false;
}


bool Tarifas::Mostrar(){
    if(Estado==true){
    cout<<endl<<"*************************************"<<endl;
    cout<<"ID de la tarifa: "<<idtarifa<<endl;
    cout<<"HORARIO INICIO TARIFA: "<<horainicio<<"  FINALIZA A LAS: "<<horafin<<endl;
    cout<<"El kilometraje minimo sin descuento de: "<<kilometrajemaximo<<endl;
    cout<<"PRECIO POR KM: "<<precio_km<<"$"<<endl;
    cout<<endl<<"*************************************"<<endl;
    return true;
    }else{
    cout << "No se pudo mostrar Tarifas." << endl;
    return false;
    }
}

void mostrarTarifa(){
    Tarifas reg;
    int pos=0;

    while(reg.leerDeDisco(pos++)){
            if(reg.getEstadoTarifa()==true){
        reg.Mostrar();
        cout<<endl;
        }
    }
    system("pause>nul");
}


void MostrarporNumeroDeTarifa(){
    system("cls");
    int DNIC,pos;
        Tarifas reg;
    cout<<"INGRESE EL NUMERO DE TARIFA A MOSTRAR: "<<"\t";
                cin>>DNIC;

                pos=buscarIdDeTarifa(DNIC);
                if(pos>=0){
                    cout<<endl<<endl;
                    reg.leerDeDisco(pos);
                    if(reg.getEstadoTarifa()==true){
                    reg.Mostrar();

               }else cout<<"EL ID DE TARIFA FUE BORRADO.";
                }else{
                    cout<<"NO EXISTE ESE NUMERO DE TARIFA EN LA BASE DE DATOS.";
                }
                system("pause>nul");}

void modificarprecio(){
       Tarifas reg;
       int num, pos,precio;
    cout<<endl<<"***************MODIFICAR PRECIO POR KM*************************"<<endl;

    cout<<endl<<"INGRESE EL NUMERO DE LA TARIFA A MODIFICAR  precio por km: ";
    cin>>num;

    pos=buscarIdDeTarifa(num);

    if(pos!=-1){
             cout<<"INGRESE EL NUEVO PRECIO POR KM DE LA TARIFA: ";
    cin>>precio;
    cout<<endl<<endl;
    reg.leerDeDisco(pos);
    reg.setPrecioporKM(precio);
        if(reg.modificarendisco(pos)==true)cout<<endl<<"MODIFICACION DE PRECIO AGREGADA."<<endl;;
      }else cout<<endl<<"El NUMERO DE TARIFA NO EXISTE"<<endl;
  }

bool bajalogicaTarifa(){
    system("cls");
    int DNIC,pos;
    bool modifico;
        Tarifas reg;
        cout<<endl<<"************BAJA DE TARIFA**********"<<endl<<endl;
    cout<<"INGRESE EL NUMERO DE TARIFA A dar de baja: "<<"\t";
                cin>>DNIC;
             //  system("cls");
                pos=buscarIdDeTarifa(DNIC);
                if(pos==-1){
                        cout<<"NO EXISTE EL NUMERO DE TARIFA ";
                return false;
                }else{
                reg.leerDeDisco(pos);
                reg.setEstadoTarifa(false);
                modifico=reg.modificarendisco(pos);
                return modifico;
                }
}

#endif // CLASSTARIFAS_H_INCLUDED
