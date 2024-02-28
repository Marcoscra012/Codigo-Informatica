#include <stdio.h>

int main(){
    int x;
    int *px; // Save memory adress of another var
    x = 2;
    px = &x;
    // y = 3;

    printf("x memory address: %x \n", &x);
    printf("x value: %d \n", x);
    printf("x pointer: %x \n", px);
    printf("x pointer pointer: %x \n", &px);
    printf("x value from its pointer: %d \n", *px);

    // printf("y: %x \n", &y);

    return 0;
}