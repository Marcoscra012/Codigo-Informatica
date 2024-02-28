#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Escriba una función que reciba una matriz 3×3 rellena de O y X y devuelva 1 si las O forman 3 en raya,
// -1 si son las X las que forman 3 en raya y 0 en el resto de casos. El reto es hacerlo con punteros

int verificadora_matriz(char **matriz){
    int respuesta = 0;

    return respuesta;
}

int main(void) {
  //Definimos las variables
  char *matriz[3];
  int fil,col;
  int seed;
  int dado;
  seed=time(0);
  srand(seed);

  //Reservamos memoria y rellenamos la matriz de O y X
  for(fil=0;fil<3;fil++){
    matriz[fil]=(char *) malloc(3*sizeof(char));
    for(col=0;col<3;col++){
      dado=rand()%2;
      if(dado==0){
        *(*(matriz+fil) +col)='O';
      }
      else{
        *(*(matriz+fil) +col)='X';
      }
    }
  }
  //MOSTRAMOS LA MATRIZ
  for(fil=0;fil<3;fil++){
    printf("\n");
    for(col=0;col<3;col++){
      printf(" %c",*(*(matriz+fil) +col));
    }
  }

  if(verificadora_matriz(matriz) == 1) printf("\nHan ganado las O");
  else if(verificadora_matriz(matriz) == 0) printf("\nHan ganado las X");
  else if(verificadora_matriz(matriz) == -1) printf("\nHay 3 en raya de X y de O");
  else printf("\nNo hay 3 en raya");

  return 0;
}