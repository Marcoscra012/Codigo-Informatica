#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NROW 10
#define NCOL 10
#define NCELL 40


// Any live cell with fewer than two live neighbours dies, as if by underpopulation.
// Any live cell with two or three live neighbours lives on to the next generation.
// Any live cell with more than three live neighbours dies, as if by overpopulation.
// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

int dice(){
    int random = rand()%NROW; //5 x 5 matrix
    // printf("random: %d", random);
    return random;
}


void check(int mat[NROW][NCOL], int c_main_mat[NROW][NCOL]){
    int c_row = 0;
    int c_col = 0;
    int c_mat[NROW][NCOL];
    int i;
    int j;

    // Fill c_mat with 0
    for(c_row = 0; c_row < NROW; c_row++) for(c_col = 0; c_col < NCOL; c_col++) c_mat[c_row][c_col] = 0;

    // Chech main matrix and modify control matrix
    for(c_row = 0; c_row < NROW; c_row++){
        for(c_col = 0; c_col < NCOL; c_col++){ // per each cell in main matrix
            for(i = c_row-1; i<=c_row+1; i++){
                if(i >= 0 && i < NROW){ // If row check it's not out of bounds
                    for(j = c_col-1; j<=c_col+1; j++){
                        if(j >= 0 && j < NCOL){ // If column check it's not out of bounds
                            if(i !=c_row || j !=c_col){ // Same cell in main matrix and c_mat -> don't check
                                if(mat[i][j] == 1){
                                    c_mat[c_row][c_col]++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for(i = 0; i < NROW; i++){
        for(j = 0; j < NCOL; j++){
            c_main_mat[i][j] = c_mat[i][j];
        }
    }
}


void life(int mat[NROW][NCOL], int c_mat[NROW][NCOL]){    
    int row;
    int col;

    for(row = 0; row < NROW; row++){
        for(col = 0; col < NCOL; col++){
            if (mat[row][col] == 1 && c_mat[row][col] < 2) mat[row][col] = 0; // Any live cell with fewer than two live neighbours dies, as if by underpopulation.
            if (mat[row][col] == 1 && c_mat[row][col] > 3) mat[row][col] = 0; // Any live cell with more than three live neighbours dies, as if by overpopulation.
            if (mat[row][col] == 0 && c_mat[row][col] == 3) mat[row][col] = 1; // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
        }
    }
}

int main(){
    int mat[NROW][NCOL]; // Main cell matrix
    int c_main_mat[NROW][NCOL]; // Count matrix (how many adjacent cells has each cell)
    int row; 
    int col;
    int n;
    int loop = 0;

    srand(time(NULL));

    // Fill mat with 0
    for(row = 0; row < NROW; row++){
        for(col = 0; col < NCOL; col++){
            mat[row][col] = 0;
            c_main_mat[row][col] = 0;
        }
    }

    // Place cells
    for(n = 0; n < NCELL; n++){ // Place NCELL cells
        row = dice();
        col = dice();
        mat[row][col] = 1;
    }

    printf("How many cycles do you want?: ");
    scanf("%d", &n);

    while(loop < n){ // Main loop
        // Print matrix
        printf("\n");
        for(row = 0; row < NROW; row++){
            for(col = 0; col < NCOL; col++){
                if(mat[row][col] == 1) printf("* ");
                else printf("%d ", mat[row][col]);
            }
            printf("\n");
        }
        check(mat, c_main_mat); // Count adjacent cells   
        life(mat, c_main_mat); // Check rules (l. 9-12) and modify main matrix
        loop++;
    }
    
    return 0;
}