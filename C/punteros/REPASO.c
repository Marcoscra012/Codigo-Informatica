#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NPERSONAS

int main(){
    int *cursos[6]; // Lista de notas de 6 cursos distintos (Lista de punteros)
    int primero[NPERSONAS];
    
    // El primer asterisco indica contenido del PTR
    // *(*cursos+3) // curso 0, mem_add 3(content)
    // *(*(cursos+1)+9) // curso 1, mem_add 9(content) 
    
    return 0;
}