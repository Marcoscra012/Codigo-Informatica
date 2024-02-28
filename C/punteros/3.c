#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define NPALABRAS 5

//Escribe un programa que reciba 10 palabras
//Las guarde en una lista de punteros, haciendo reserva dinámica
//de memoria con malloc y las ordene por su longitud de menor a mayor

int main(void) {
  //Defino el vector de punteros
  char *palabras[NPALABRAS];
  char *pintercambio;
  char auxiliar[15];
  int cont;
  int longitud;
  int nveces;
  //Defino el resto de las variables


  //Leo las palabras
  for(cont=0;cont<NPALABRAS;cont++){
    printf("\nEscriba la palabra %d: ",cont+1);
    scanf(" %s", auxiliar);
    longitud=strlen(auxiliar);
    palabras[cont]=(char *) malloc(longitud*sizeof(char));
    strcpy(palabras[cont], auxiliar);
  }
  //Muestro la lista tal cual
  printf("\n************************");
  printf("\n*  LISTA DE PALABRAS   *");
  printf("\n************************");
  for(cont=0;cont<NPALABRAS;cont++){
    printf("\n %s",palabras[cont]);
  }
  //Ordeno la lista por su longitud por el método de la burbuja
  for(nveces=1;nveces<NPALABRAS-1;nveces++){
    for(cont=0;cont<NPALABRAS-1;cont++){
      printf("\nlongitud palabra %d:%d",cont,strlen(palabras[cont]));
      printf("\nlongitud palabra %d:%d",cont+1,strlen(palabras[cont+1]));
      if(strlen(palabras[cont])>strlen(palabras[cont+1])){
        printf("\nCambio %d con %d",cont,cont+1);
        pintercambio=palabras[cont];
        palabras[cont]=palabras[cont+1];
        palabras[cont+1]=pintercambio;
      }
    }

  }

  //Vuelvo a mostrar la lista
  printf("\n********************************");
  printf("\n*  LISTA DE PALABRAS ORDENADA  *");
  printf("\n********************************");
  for(cont=0;cont<NPALABRAS;cont++){
    printf("\n %s",palabras[cont]);
  }





  return 0;
}