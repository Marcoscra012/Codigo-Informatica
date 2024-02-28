#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int main(){
    int numeros[3];
    srand(time(0));

    for(int i = 0; i < SIZE; i++) *(numeros+i) = rand()%10;

    for(int i = 0; i < SIZE; i++) printf("numeros = %d\n", *(numeros+i));

    return 0;
}