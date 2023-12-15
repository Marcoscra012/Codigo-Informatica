#include <stdio.h>

int esDivisor(int num, int divisor){
    int respuesta = 0;
    if (num%divisor == 0) respuesta = 1;
    return respuesta;
}

int esPrimo(int num){
    int respuesta = 1;
    for (int n = num-1; n > 1; n--){
        if (num % n == 0) respuesta = 0;
    }
    return respuesta;
}

int comprobar(int num){
    for (int i = num; i > 1; i--){
        if (esPrimo(i) == 1){
            if (esDivisor(num, i) == 1) {
                printf("\n%d", i);
                return (num / i);
            }
        }
    }
}

int main(){
    int num;
    int desc;
    
    //Pedir el numero
    printf("Escribe un numero: ");
    scanf("%d", &num);

    //Descomponer
    desc = num;
    while (desc > 1){
        desc = comprobar(desc);
    }
    printf("\n1");

    return 0;
}