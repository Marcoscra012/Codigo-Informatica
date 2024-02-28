#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NPALABRAS 5
#define MAXLETRAS 10

int comprobador_palabras(char palabra_check[MAXLETRAS*2]){
    int validez_check;
    if(strlen(palabra_check) > 10) validez_check = 0; // La palabra mas de 10 letras
    else validez_check = 1; // La palabra tiene 10 o menos letras

    if(validez_check == 0) printf("\nLa palabra es muy larga");

    return validez_check;
}

void contar_consonantes_vocales(char *palabras[NPALABRAS]){
    int n_cons;
    for(int i = 0; i < NPALABRAS; i++){
        for(int j = 0; j < len(palabras[i]; j++)){
            if(palabras[i][j] == 'a' || palabras[i][j] == 'e' || palabras[i][j] == 'i' || palabras[i][j] == 'o' || palabras[i][j] == 'u' ||
            palabras[i][j] == 'A' || palabras[i][j] == 'E' || palabras[i][j] == 'I' ||palabras[i][j] == 'O' || palabras[i][j] == 'U')
        }
    }
}

int main(){
    char *palabras[NPALABRAS];
    char palabra[20];
    int validez;

    char consonantes[20];

    // Reservar memoria para palabras
    for(int i = 0; i < NPALABRAS; i++){
        validez = 0;
        while(validez == 0){    
            printf("\nEscriba la palabra %d: ", i+1);
            scanf(" %s", palabra);
            validez = comprobador_palabras(palabra);
        }

        palabras[i] = (char *) malloc(strlen(palabra) * sizeof(char));
        strcpy(palabras[i], palabra);
    }

    // print palabras
    for(int i = 0; i < NPALABRAS; i++){
        printf("\nPalabra %d: %s", i+1, *(palabras+i));
    }
}