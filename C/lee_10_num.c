#include <stdio.h>

int main(){
    int numero[10];
    
    //Leemos 10 numeros
    for(int i=0; i<10; i++){
        printf("\nNumero %d: ", i+1);
        scanf("%d", &numero[i]);
    }

    //Los mostramos por pantalla
    for(int i=0; i<10; i++){
        printf("\nEl numero %d es %d", i+1, numero[i]);
    }

    return 0;
}