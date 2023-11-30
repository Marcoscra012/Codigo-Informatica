#include <stdio.h>

int main(){
    int num1;
    int num2;
    int num3;

    printf("Escribe un numero: ");
    scanf("%d", &num1);
    printf("Escribe otro numero: ");
    scanf("%d", &num2);
    printf("Escribe un ultimo numero: ");
    scanf("%d", &num3);

    if(num1>num2 && num1>num3){ //num1 es el mayor
        printf("El mayor numero es %d", num1);
    }
    else if(num2>num1 && num2>num3){ //num2 es el mayor
        printf("El mayor numero es %d", num2);
    }
    else if(num3>num1 && num3>num2){ //num3 es el mayor
        printf("El mayor numero es %d", num3);
    }
   
    return 0;
}