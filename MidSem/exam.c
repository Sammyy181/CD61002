#include <stdio.h>
#include <stdlib.h>

void get_matrix(double** COEF, int** JCOEF, int n, int D){

    double** A;
    A = (double**)calloc(n, sizeof(double*));
    for(int i = 0; i < n; i++){
        A[i] = (double*)calloc(n, sizeof(double));
    }

    int row, col;
    int id_y;

    for(row = 0; row < n; row++){
        for(col = 0; col < D; col++){
            if(COEF[row][col] != 0.0) {
                id_y = JCOEF[row][col] - 1;
                A[row][id_y] = COEF[row][col];
            }
        }
    }

    FILE *fp1 = fopen("testMatrix.txt", "w");
    if (fp1 == NULL) {
        perror("Error opening matrix.txt");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(fp1, "%.1f ", A[i][j]);
        }
        fprintf(fp1, "\n");
    }
    fclose(fp1);

}