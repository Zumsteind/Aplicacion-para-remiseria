#ifndef CLASSSEGUROS_H_INCLUDED
#define CLASSSEGUROS_H_INCLUDED
#include "classfecha.h"
#include "prototipos.h"

class SegurosporAuto: public Fecha{
protected:
    char Patente[8];
    int DNI_Cond;
    Fecha fecha_vigencia_seguro;
    bool Estado_seguro;// <-- Deberá tomar dos estados, entre "Vigente" o "Vencido" para determinar la condición del seguro
   // bool EstadoArchivoSeg;
public:
    // gets
    int getDNIConductor(){return DNI_Cond;}
    char *getPatente(){return Patente;}
    Fecha getFechaVigenciaSeguro(){return fecha_vigencia_seguro;}
    bool getestadoSeguro(){return Estado_seguro;}
   // bool getestadoArchivoSeg(){return EstadoArchivoSeg;}

    // sets
    void setDNIConductor(int DNIC){DNI_Cond = DNIC;}
    void setPatente(char *p_seguro){strcpy(Patente, p_seguro);}
    void setFechaVigenciaSeguro(Fecha fecha_seguro){fecha_vigencia_seguro=fecha_seguro;}
    void setEstadoSeguro(bool state_seg){Estado_seguro=state_seg;}
 // void setEstadoArchivoSeg(bool state_file_seg){EstadoArchivoSeg=state_file_seg;}

    bool Cargar();
    bool Mostrar();

    ///archivos

        bool grabarEnDisco(){
        FILE *pSeg;
        bool grabo;
        pSeg=fopen("Seguros.dat","ab");
        if(pSeg==NULL){
            return false;
        }
        grabo=fwrite(this,sizeof *this,1,pSeg);

        fclose(pSeg);
        return grabo;
        }

        bool leerDeDisco(int pos){
        FILE *pSeg;
        bool leyo;
        pSeg=fopen("Seguros.dat", "rb");
        if(pSeg==NULL){
            return false;
        }
        fseek(pSeg,pos*sizeof *this,0);
        leyo=fread(this,sizeof *this,1,pSeg);
        fclose(pSeg);
        return leyo;
        }

        bool leerDeBu(int pos){
        FILE *pSeg;
        bool leyo;
        pSeg=fopen("Seguros.bkp", "rb");
        if(pSeg==NULL){
            return false;
        }
        fseek(pSeg,pos*sizeof *this,0);
        leyo=fread(this,sizeof *this,1,pSeg);
        fclose(pSeg);
        return leyo;
        }

     bool modificarEnDisco(int pos){
        FILE *pSeg;
        bool modifico;
        pSeg=fopen("Seguros.dat", "rb+");
        if(pSeg==NULL){
            return false;
        }
        fseek(pSeg,pos*sizeof *this,0);
        modifico=fwrite(this,sizeof *this,1,pSeg);
        fclose(pSeg);
        return modifico;
    }

};
int BuscarPatente(char n[30]){
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

bool SegurosporAuto::Cargar(){

    cout<<endl<<"******************SEGURO DE VEHICULO/s****************"<<endl;
    cout<<"Ingrese la patente del vehiculo: ";
    cargarCadena(Patente,8);
    if(BuscarPatente(Patente)==-1){
            cout<<endl<<"PATENTE NO REGISTRADA EN VEHICULOS:";
    return false; }
    cout<<"Ingrese la fecha de vigencia del seguro: ";
    fecha_vigencia_seguro.Cargar();
    cout<<"DNI del Propietario: ";
    cin>>DNI_Cond;
    Estado_seguro=true; /// Vigente
    return Estado_seguro;
}

bool SegurosporAuto::Mostrar(){
    if(Estado_seguro==true){
    cout<<"Patente del vehiculo: " << Patente << endl;
    cout<<"DNI DE Propietario: "<<DNI_Cond<<endl;

        cout<<"Seguro renovado por ultima vez el: ";
        fecha_vigencia_seguro.Mostrarfecha();
        cout << endl;
        return true;

    }else{
    cout << "No se pudo mostrar los seguros." << endl;
    return false;
    }
}


bool cargarSeguro(){
       SegurosporAuto aux;
       system("cls");
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
        cout<<endl;
        }else{
             cout<<"Cargar esta en falso....";
             return false;
             }
}

void mostrarSeguro(){
    SegurosporAuto reg;
    int pos=0;
     system("cls");
        while(reg.leerDeDisco(pos++)){
                if(reg.getestadoSeguro()==true){
                    reg.Mostrar();
                    cout<<endl;
                }
        }
    system("pause>nul");
}

int buscarPatenteSeguros(char n[8]){
    SegurosporAuto reg;
    int pos = 0;
    while(reg.leerDeDisco(pos)){
        if(strcmp(n,reg.getPatente())==0){
            return pos;
        }
        pos++;
    }
    return -1;
}

int buscar_patseg(char *pat)
{
    int pos=0;
    SegurosporAuto reg;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(pat,reg.getPatente())==0){
            return pos;}
        pos++;
    }
    return -1;
}


void MostrarSeguroporPatente(){
    system("cls");
    int pos;
    char patente_nueva[8];
        SegurosporAuto obj;
        cout<<"Ingrese PATENTE de SEGURO a mostrar: ";
                cargarCadena(patente_nueva,8);

                pos=buscar_patseg(patente_nueva);
                if(pos>=0){
                    cout<<endl<<endl;
                    obj.leerDeDisco(pos);
                    if(obj.getestadoSeguro()==true){
                    obj.Mostrar();
                       }else cout<<"LA PATENTE FUE BORRADA DE LA BASE DE DATOS.";
                        }else{
                            cout<<"NO EXISTE ESA PATENTE EN LA BASE DE DATOS.";
                        }
                system("pause>nul");
}





bool modifica_patente_seguro(){
    char patente[8];
    int pos;
    SegurosporAuto reg;
    Fecha fecha_vigencia_seguros;

    system("cls");
    cout<<"Ingrese PATENTE a modificar:";
    cin>>patente;
    pos=buscarPatenteSeguros(patente);
    cout << "POS: " << pos << endl;

    if(pos!=-1)
        {
        reg.leerDeDisco(pos);
        cout<<"Ingrese la nueva fecha: ";
        fecha_vigencia_seguros.Cargar();
        reg.setFechaVigenciaSeguro(fecha_vigencia_seguros);
        reg.modificarEnDisco(pos);
        system("pause");
        return true;
        }
    else
        {
        cout<<"No existe la patente"<<endl;
        cout<<"Presione una tecla para continuar";
        system("pause>null");
        return false;
        }
}


bool bajalogicaSeguros(){
    system("cls");
    int pos=0;
    char patente_nueva[8];
    bool modifico;
        SegurosporAuto reg;
    cout<<"INGRESE LA PATENTE DEL SEGURO A DAR DE BAJA: " <<"\t";
                cin>>patente_nueva;
                pos=buscarPatenteSeguros(patente_nueva);
                if(pos==-1){
                        cout<<"NO EXISTE LA PATENTE INGRESADA.";
                return false;
                }else{
                reg.leerDeDisco(pos);
                reg.setEstadoSeguro(false);
                modifico=reg.modificarEnDisco(pos);
                return modifico;
                }
}


#endif // CLASSSEGUROS_H_INCLUDED
