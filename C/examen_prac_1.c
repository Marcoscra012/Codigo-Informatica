#include <stdio.h>
#include <string.h>
#define LETRASMAX 20

int main(){
    char *lista[2];
    char palabra1[LETRASMAX];
    char palabra2[LETRASMAX];
    int longitud;
    int n = 0;

    printf("Escriba una palabra: ");
    scanf(" %s", &palabra1);

    lista[0] = palabra1;
    longitud = strlen(palabra1);

    for(int i = 0; i < longitud; i++){
        palabra2[i] = palabra1[longitud-1-i];
    }

    lista[1] = palabra2;
    printf("\nPalabra invertida: %s", lista[1]);
    for(int i = 0; i < longitud; i++){
        if(palabra1[i] == palabra2[i]) n += 1;
    }
    if (n == longitud) printf("\nLas palabras son palindromos");
    else printf("\nLas palabras no son palindromos");
}