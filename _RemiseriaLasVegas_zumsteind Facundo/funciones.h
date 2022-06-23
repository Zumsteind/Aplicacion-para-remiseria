#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "prototipos.h"

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

float obtenerprecio(float inicio, float fin, int costo){
    float precio, duracion;
    if(fin<inicio){
        duracion=(24-inicio)+fin;
    }
    else{
        duracion=fin-inicio;
    }
    precio=(duracion*costo);
    return precio;
}



#endif // FUNCIONES_H_INCLUDED
