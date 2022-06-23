#ifndef CLASSFECHA_H_INCLUDED
#define CLASSFECHA_H_INCLUDED

class Fecha{

private:
        int dia, mes, anio;
    public:

///gets mostrar
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
///sets modificar

        void setDia(int d){dia=d;}
         void setMes(int m){mes=m;}
          void setAnio(int a){anio=a;}

        bool Cargar(){

            int d;
            int m;
            int a;
    cout << "Ingrese el Dia: ";
    cin >> d;
    setDia(d);
    cout << "Ingrese el Mes: ";
    cin >> m;
    setMes(m);
    cout << "Ingrese el anio: ";
    cin >> a;
    setAnio(a);
            if(dia>0 && dia<=31 ){
                if(mes>0 && mes<=12){
                    if(anio>1940 &&anio<=2022){
                        if(anio==2022 && mes>=2 && dia>24){

                            return false;
                        }
                        return true;
                    }
                }
            }

            return false;
        }
        void Mostrarfecha(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
};


#endif // CLASSFECHA_H_INCLUDED
