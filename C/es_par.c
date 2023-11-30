#include <stdio.h>

int es_par(int num){
    if(num%2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int num;

    printf("Introduce un numero entero: ");
    scanf("%d", &num);

    if(es_par(num) == 1){
        printf("El numero introducido es par");
        return 1;
    }
    else{
        printf("El numero introducido es impar");
        return 0;
    }
}