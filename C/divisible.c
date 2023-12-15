#include <stdio.h>

int divisible2(int num){
    if (num % 2 == 0) printf("\nEl numero es divisible entre 2");
}

int divisible3(int num){
    if (num % 3 == 0) printf("\nEl numero es divisible entre 3");
}

int divisible5(int num){
    if (num % 5 == 0) printf("\nEl numero es divisible entre 5");
}

int divisible7(int num){
    if (num % 7 == 0) printf("\nEl numero es divisible entre 7");
}

int main(){
    int num;
    
    //Pedir los numeros
    printf("Escribe un numero: ");
    scanf("%d", &num);

    //Ejecutar las funciones
    divisible2(num);
    divisible3(num);
    divisible5(num);
    divisible7(num);

    return 0;
}