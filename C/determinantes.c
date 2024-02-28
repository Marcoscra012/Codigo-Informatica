#include <stdio.h>

/*
    INF                 REAL
00 01 02 03     |   11 12 13 14
10 11 12 13     |   21 22 23 24
20 21 22 23     |   31 32 33 34
30 31 32 33     |   41 42 43 44
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
    int res;
    int temp;
    int temp_matriz;
    int i;
    int j;
    int t_i;
    int t_j;

    for(i = 1; i < orden; i++){
        for(j = 0; j < orden; j++){
            // crear una matriz temporal
            for(t_i = 1; t_i < orden-1; t_i++){
                for(t_j = 0; t_j < orden-1; t_j++){
                    if(t_j != j){
                        temp_matriz[t_i][t_j] = matriz[t_i][t_j];
                    }
                }
            }
            temp = matriz[0][j] * (-1**(1+j+1)) * matriz_3(temp_matriz);
        }
    }

    return res;
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