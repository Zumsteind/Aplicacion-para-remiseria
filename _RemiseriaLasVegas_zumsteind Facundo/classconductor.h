#ifndef CLASSCONDUCTOR_H_INCLUDED
#define CLASSCONDUCTOR_H_INCLUDED
#include "classfecha.h"
#include "prototipos.h"

class Conductores{
private:
	int DNI_Cond;
	char Nombre[30];
    char Apellido[30];
    char Domicilio[40];
    char Email[50];
    Fecha fechadeingreso;
    bool Estado;
public:
    //gets()
    int getDNIConductor(){return DNI_Cond;}
    char *getNombre(){return Nombre;}
    char *getApellido(){return Apellido;}
    char *getDomicilioConductores(){return Domicilio;}
    char *getEmailConductores(){return Email;}
    void setfechaConductores(Fecha fecha_c){fechadeingreso=fecha_c;}
    bool getEstadoConductores(){return Estado;}
    //sets()
    void setDNIConductor(int DNIC){DNI_Cond = DNIC;}
    void setNombre(const char *nom_conductor){strcpy(Nombre, nom_conductor);}
    void setApellido(const char *ap_conductor){strcpy(Apellido, ap_conductor);}
    void setDomicilioConductores(const char *direc_conductor){strcpy(Domicilio, direc_conductor);}
    void setEmailConductores(const char *email_conductor){strcpy(Email, email_conductor);}
    Fecha getfechaConductores(){return fechadeingreso;}
    void setEstadoConductores(bool state_conduc){Estado = state_conduc;}

    // metodos
	bool Cargar();
	bool Mostrar();

	//archivos

        bool grabarEnDisco(){
        FILE *pCond;
        bool grabo;
        pCond=fopen("Conductor.dat","ab");
        if(pCond==NULL){
            return false;
        }
        grabo=fwrite(this,sizeof *this,1,pCond);
        fclose(pCond);
        return grabo;
        }

        bool leerDeDisco(int pos){
        FILE *pCond;
        bool leyo;
        pCond=fopen("Conductor.dat", "rb");
        if(pCond==NULL){
            return false;
        }
        fseek(pCond,pos*sizeof *this,0);
        leyo=fread(this,sizeof *this,1,pCond);
        fclose(pCond);
        return leyo;
        }

        bool leerDeBu(int pos){
        FILE *pCond;
        bool leyo;
        pCond=fopen("Conductor.bkp", "rb");
        if(pCond==NULL){
            return false;
        }
        fseek(pCond,pos*sizeof *this,0);
        leyo=fread(this,sizeof *this,1,pCond);
        fclose(pCond);
        return leyo;
        }
     bool modificarendisco(int pos){
        FILE *pCond;
        bool leyo;
        pCond=fopen("Conductor.dat", "rb+");
        if(pCond==NULL){
            return false;
        }
        fseek(pCond,pos*sizeof *this,0);
        leyo=fwrite(this,sizeof *this,1,pCond);
        fclose(pCond);
        return leyo;
        }
};

bool Conductores::Cargar(){
    cout<<endl<<"************AGREGAR CONDUCTOR NUEVO*********"<<endl;

    cout<<"DNI del conductor: ";
    cin>>DNI_Cond;
    if(buscarDni(DNI_Cond)!=-1){
        cout<<"EL CONDUCTOR YA SE ENCUENTRO EN LA BASE DE DATOS";
        return false;
    }
    cout<<"Nombre del conductor: ";
    cargarCadena(Nombre,30);
    cout<<"Apellido del conductor: ";
    cargarCadena(Apellido,30);
    cout<<"Correo electronico del conductor: ";
    cargarCadena(Email,50);
    cout<<"Domicilio del conductor: ";
    cargarCadena(Domicilio,40);
    cout<<"Ingrese fecha de ingreso:  ";
    if(fechadeingreso.Cargar()==true){
    }else{cout<<endl<<"FECHA INVALIDA"<<endl;
    system("pause");
    return false;};

    cout<<endl<<"************FIN DE CARGA DE DATOS***************";
    Estado=true;


    return Estado;

}


bool cargarConductor(){
    Conductores aux;
    if(aux.Cargar()==true){

    if(aux.grabarEnDisco()==true){
        cout<<endl<<endl<<"REGISTRO AGREGADO.";
        system("pause>nul");
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO";
    }
    cout<<endl;
    }else cout<<"cargar esta en falso....";
    return true;
}

bool Conductores::Mostrar(){
    if(Estado==true){
    cout<<endl<<"****************************"<<endl;
    cout<<"DNI DE CONDUCTOR: "<<DNI_Cond<<endl;
    cout<<"NOMBRE: "<<Nombre<<endl;
    cout<<"APELLIDO: "<<Apellido<<endl;
    cout<<"EMAIL: "<< Email<<endl;
    cout<<"FECHA DE INGRESO: ";fechadeingreso.Mostrarfecha();
    cout<<"DOMICILIO: "<<Domicilio<<endl;
    cout<<endl<<"****************************"<<endl;
    return Estado;
    }else{
        cout << "No se pueden mostrar los datos." << endl;
        return Estado;
    }
}

void mostrarConductores(){
    Conductores reg;
    int pos=0;

    while(reg.leerDeDisco(pos++)){
            if(reg.getEstadoConductores()==true){
            reg.Mostrar();
            cout<<endl;
            }

    }
    system("pause>nul");
}

int buscarDni(int n){
    Conductores reg;
    int pos =0;
    while(reg.leerDeDisco(pos)){

        if(reg.getDNIConductor()==n){
            return pos;
        }
        pos++;
    }
    return -1;
}


void MostrarporDni(){
    system("cls");
    int DNIC,pos;
    Conductores reg;
    cout<<"INGRESE EL DNI DEL CONDUCTOR A MOSTRAR: "<<"\t";
    cin>>DNIC;
                pos=buscarDni(DNIC);
                if(pos>=0){
                    cout<<endl<<endl;
                    reg.leerDeDisco(pos);
                    if(reg.getEstadoConductores()==true){
                    reg.Mostrar();
                    }else cout<<"CONDUCTOR FUE BORRADO DE LA BASE DE DATOS.";
                }else{
                    cout<<"NO EXISTE ESE DNI EN LA BASE DE DATOS.";
                }
                system("pause>nul");
}

bool bajalogicaConductores(){
    system("cls");
    int DNIC,pos;
    bool modifico;
        Conductores reg;
    cout<<"INGRESE EL DNI DEL CONDUCTOR A dar de baja: "<<"\t";
                cin>>DNIC;
                pos=buscarDni(DNIC);
                if(pos==-1){
                        cout<<"NO EXISTE EL DNI DEL CONDUCTOR.";
                return false;
                }else{
                reg.leerDeDisco(pos);
                reg.setEstadoConductores(false);
                modifico=reg.modificarendisco(pos);
                return modifico;
                }
}


#endif // CLASSCONDUCTOR_H_INCLUDED
