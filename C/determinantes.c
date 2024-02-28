#include <stdio.h>

/*
No esta terminado pero hace determinantes de matrices cuadradas de orden 2 y 3
*/

int matriz_2(int matriz[2][2]){
    int res;

    res = (matriz[0][0]*matriz[1][1]) - (matriz[0][1] * matriz[1][0]);

    return res;
}

int matriz_3(int matriz[3][3]){
    int op1_1;
    int op1_2;
    int op1_3;
    int op2_1;
    int op2_2;
    int op2_3;
    int res;

    op1_1 = matriz[0][0] * matriz[1][1] * matriz[2][2];
    op1_2 = matriz[0][1] * matriz[1][2] * matriz[2][0];
    op1_3 = matriz[1][0] * matriz[2][1] * matriz[0][2];

    op2_1 = matriz[0][2] * matriz[1][1] * matriz[2][0];
    op2_2 = matriz[0][1] * matriz[1][0] * matriz[2][2];
    op2_3 = matriz[1][2] * matriz[2][1] * matriz[0][0];

    res = op1_1 + op1_2 + op1_3 - op2_1 - op2_2 - op2_3;

    printf("op1_1 = %d \nop1_2 = %d \nop1_3 = %d \nop2_1 = %d \nop2_2 = %d \nop2_3 = %d \n", op1_1, op1_2, op1_3, op2_1, op2_2, op2_3);

    return res;
}

int matriz_4(int orden, int matriz[orden][orden]){
    return 0;
}

int main(){
    int orden;
    int i;
    int j;
    int det;
    
    printf("ESCRIBE EL ORDEN DE LA MATRIZ CUADRADA: ");
    scanf("%d", &orden);

    int matriz[orden][orden];

    for(i = 0; i < orden; i++){
        for(j = 0; j < orden; j++){
            printf("\nEscribe el numero en la posicion %d , %d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    if(orden == 2) det = matriz_2(matriz);
    if(orden == 3) det = matriz_3(matriz);
    if(orden >= 4) det = matriz_4(orden, matriz);

    // Print matriz
    printf("\n");
    for(i = 0; i < orden; i++){
        for(j = 0; j < orden; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nDETERMINANTE: %d", det);
    
    return 0;
}
