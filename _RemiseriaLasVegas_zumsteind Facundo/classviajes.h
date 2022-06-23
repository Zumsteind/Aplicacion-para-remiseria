#ifndef CLASSVIAJES_H_INCLUDED
#define CLASSVIAJES_H_INCLUDED
#include "classfecha.h"
#include "prototipos.h"

class Viajes{
private:
	int DNI_Cond;
	Fecha fecha_viaje;
	int Hora;
	int num_viaje;
	float cantKm;

    bool Estado;
   /// float valor;
public:
    //gets()
   /// int getvalor(){return valor;}
    int getDNIConductor(){return DNI_Cond;}

    Fecha getFechaViaje(){return fecha_viaje;}
    int getNumerodeViaje(){return num_viaje;}
    int getHora(){return Hora;}
    int getcatkm(){return cantKm;}
    bool getEstadoViajes(){return Estado;}

    //sets()
    void setDNIConductor(int DNIC){DNI_Cond = DNIC;}

   /// void setvalor(int val){valor = val;}
    void setfechaViajes(Fecha fecha_v){fecha_viaje=fecha_v;}
    void setNumeroDeViaje(int numdv){num_viaje=numdv;}
    void setHora(int h){Hora=h;}
    void setcantKm(int km){cantKm=km;}
    void setEstadoViajes(bool state_viajes){Estado = state_viajes;}

	bool Cargar();
	void Mostrar();

	///archivos

        bool grabarEnDisco(){
        FILE *pVia;
        bool grabo;
        pVia=fopen("Viajes.dat","ab");
        if(pVia==NULL){
            return false;
        }
        grabo=fwrite(this,sizeof *this,1,pVia);
        fclose(pVia);
        return grabo;
        }

        bool leerDeDisco(int pos){
        FILE *pVia;
        bool leyo;
        pVia=fopen("Viajes.dat", "rb");
        if(pVia==NULL){
            return false;
        }
        fseek(pVia,pos*sizeof *this,0);
        leyo=fread(this,sizeof *this,1,pVia);
        fclose(pVia);
        return leyo;
        }

        bool leerDeBu(int pos){
        FILE *pVia;
        bool leyo;
        pVia=fopen("Viajes.bkp", "rb");
        if(pVia==NULL){
            return false;
        }
        fseek(pVia,pos*sizeof *this,0);
        leyo=fread(this,sizeof *this,1,pVia);
        fclose(pVia);
        return leyo;
        }
     bool modificarendisco(int pos){
        FILE *pVia;
        bool leyo;
        pVia=fopen("Viajes.dat", "rb+");
        if(pVia==NULL){
            return false;
        }
        fseek(pVia,pos*sizeof *this,0);
        leyo=fwrite(this,sizeof *this,1,pVia);
        fclose(pVia);
        return leyo;
        }


};


int buscarPrecioTarifa(int nt){
    Tarifas aux;
    int pos=0;
    while(aux.leerDeDisco(pos++)){

        if(nt==aux.getIDTarifa()){

            return aux.getPrecioporKM();
        }

    }
return 001;
}

int valorDeViaje(int pos){
        int precio,valor=0;
        Viajes reg;
        while(reg.leerDeDisco(pos)){

            if(reg.getHora()>=8 && reg.getHora()<14 && reg.getcatkm()<=20 ){
                precio=buscarPrecioTarifa(1);
                valor=precio*reg.getcatkm();
                    return valor;
                    }
                    if(reg.getHora()>=8 && reg.getHora()<14 && reg.getcatkm()>=20 ){
                precio=buscarPrecioTarifa(2);
                valor=precio*reg.getcatkm();
                    return valor;
                    }
                    if(reg.getHora()>=14 && reg.getHora()<24 && reg.getcatkm()<=20 ){
                precio=buscarPrecioTarifa(3);
                valor=precio*reg.getcatkm();
                    return valor;
                    }
                   if(reg.getHora()>=14 && reg.getHora()<24 && reg.getcatkm()>=20 ){
                precio=buscarPrecioTarifa(4);
                valor=precio*reg.getcatkm();
                    return valor;
                    }
                    if(reg.getHora()>=0 && reg.getHora()<8 && reg.getcatkm()<=20 ){
                precio=buscarPrecioTarifa(5);
                valor=precio*reg.getcatkm();
                    return valor;
                    }
                    if(reg.getHora()>=0 && reg.getHora()<8 && reg.getcatkm()>=20 ){
                precio=buscarPrecioTarifa(6);
                valor=precio*reg.getcatkm();
                    return valor;
                    }

            }

return -1;
}

bool VerificarFechaseguroporDNI( int dni){

    SegurosporAuto aux;
    int pos=0;
    int DIAACTUAL=16;
    int MESACTUAL=12;
    int ANIOACTUAL=2021;
        while(aux.leerDeDisco(pos++)){

            if(dni==aux.getDNIConductor()){

                if(aux.getFechaVigenciaSeguro().getAnio()<ANIOACTUAL){
                return false; }
                if(aux.getFechaVigenciaSeguro().getMes()<MESACTUAL && aux.getFechaVigenciaSeguro().getAnio()<=ANIOACTUAL){
                    return false;
                }
                if(aux.getFechaVigenciaSeguro().getDia()<DIAACTUAL && aux.getFechaVigenciaSeguro().getMes()<=MESACTUAL && aux.getFechaVigenciaSeguro().getAnio()<=ANIOACTUAL){
                    return false;
              }
                return true;

            } return false;
        }
        return false;
}

bool Viajes::Cargar(){
    cout<<"************CARGAR VIAJE**************"<<endl;
    ///Numero de viaje
    if(autoincrementar()== -1){
    num_viaje=1;
    }else{
    num_viaje=autoincrementar();
    }
        cout<<"Ingresar DNI DEL CONDUCTOR: ";
        cin>>DNI_Cond;

      if(VerificarFechaseguroporDNI(DNI_Cond)==false){

                    system("cls");
                cout<<"Conductor No habilidado para circular."<<endl;
                system("pause");
            return false;
            }

        cout<<"Ingresar fecha Del viaje : ";
        if(fecha_viaje.Cargar()==false)return false;
        cout<<"ingresar Hora de viaje, (sin minutos): ";
        cin>>Hora;
        cout<<"ingresar Cantidad total de KM del viaje: " ;
        cin>>cantKm;

        Estado=true;
        return true;
}


bool cargarViajes(){
    Viajes aux;

    if(aux.Cargar()==true){

    if(aux.grabarEnDisco()==true){
        cout<<endl<<endl<<"REGISTRO AGREGADO.";
        return true;
        system("pause>nul");
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO";
        return false;
        }
    }return false;

}


void Viajes::Mostrar(){


    cout<<endl<<"*********************"<<endl;
    cout<<"n° de viaje: " <<num_viaje <<endl;
    cout<<"DNI: "<<DNI_Cond <<endl;
    cout<<"FECHA DEL VIAJE: ";fecha_viaje.Mostrarfecha();
    cout<<"Km del viaje: "<<cantKm<<endl;
    cout<<"Hora del viaje: "<<Hora;
    cout<<endl<<"*********************"<<endl;
   /// cout<<"VALOR DE VIAJE: "<<valor<<" $";


}

bool mostrarViajes(){
    Viajes reg;
    int pos=0;
    int valor;
    while(reg.leerDeDisco(pos++)){

            if(reg.getEstadoViajes()==true){
                valor=valorDeViaje(reg.getNumerodeViaje()-1);
            reg.Mostrar();
            cout<<"Valor viaje: "<<valor;
            cout<<endl;
            }
    }
    system("pause>nul");
    return true;
}


int autoincrementar(){
    FILE *pArt;

    pArt=fopen("viajes.dat","rb");
    if(pArt==NULL){
        return -1;
    }

    fseek(pArt,0,2);
    int numviaje=ftell(pArt)/sizeof(Viajes);
    numviaje++;
    fclose(pArt);
    return numviaje;
}
int buscarNumeroDeViaje(int n){
    Viajes reg;
    int pos =0;
    while(reg.leerDeDisco(pos)){
        if(reg.getNumerodeViaje()==n){
            return pos;
        }
        pos++;
    }
    return -1;
}

void MostrarporNumeroDeViaje(){
    system("cls");
    int DNIC,pos;
    Viajes reg;
    cout<<"INGRESE EL NUMERO DE VIAJE A MOSTRAR: "<<"\t";
                cin>>DNIC;
                pos=buscarNumeroDeViaje(DNIC);
                if(pos>=0){
                    cout<<endl<<endl;
                    reg.leerDeDisco(pos);
                    if(reg.getEstadoViajes()==true){
                    reg.Mostrar();

                    }else cout<<"EL VIAJE FUE BORRADO DE LA BASE DE DATOS.";

                }else{
                    cout<<"NO EXISTE ESE NUMERO DE VIAJE EN LA BASE DE DATOS.";

                }
                system("pause>nul");
}

int buscarD(int n){
        Viajes reg;
        int pos =0;
        while(reg.leerDeDisco(pos)){
            if(reg.getDNIConductor()==n){
                return pos;
            }
            pos++;
        }
        return -1;
        }

bool MostrarporD(){
    Viajes reg;
    int pos=0;
    int DNIC, poss;

        cout<<"INGRESE EL DNI DEL CONDUCTOR A MOSTRAR: "<<"\t";
        cin>>DNIC;

        while(reg.leerDeDisco(pos++)){
            poss=buscarD(DNIC);
                        if(poss>=0){
                            cout<<endl<<endl;
                            if(reg.getDNIConductor()==DNIC){
                            reg.Mostrar();
                            return true;
                            }
                        }
        }
    return false;
}

bool bajalogicaViajes(){
    system("cls");
    int DNIC,pos;
    bool modifico;
        Viajes reg;
        cout<<endl<<"************BAJA DE VIAJE**********"<<endl<<endl;
        cout<<"INGRESE EL NUMERO DE VIAJE A dar de baja: "<<"\t";
                cin>>DNIC;
                pos=buscarNumeroDeViaje(DNIC);
                if(pos==-1){
                    cout<<"NO EXISTE EL NUMERO DE VIAJE ";
                return false;
                }else{
                reg.leerDeDisco(pos);
                reg.setEstadoViajes(false);
                modifico=reg.modificarendisco(pos);
                return modifico;
                }
}

#endif // CLASSVIAJES_H_INCLUDED
