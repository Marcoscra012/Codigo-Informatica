#include <stdio.h>

int devuelveMayor(int num1, int num2, int num3){
    if(num1>num2 && num1>num3){ //num1 es el mayor
        return num1;
    }
    else if(num2>num1 && num2>num3){ //num2 es el mayor
        return num2;
    }
    else if(num3>num1 && num3>num2){ //num3 es el mayor
        return num3;
    }
}

int main(){
    int num1;
    int num2;
    int num3;
    int mayor;

    printf("Introduce 3 numeros enteros: ");
    printf("Numero 1: ");
    scanf("%d", &num1);
    printf("Numero 2: ");
    scanf("%d", &num2);
    printf("Numero 3: ");
    scanf("%d", &num3);

    mayor = devuelveMayor(num1, num2, num3);
    printf("El mayor numero entre %d, %d y %d es %d", num1, num2, num3, mayor);

    return 0;
}