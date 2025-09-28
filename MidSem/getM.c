#include <stdio.h>
#include <stdlib.h>
#include "exam.c"

int main(){

    int n = 10;
    int D = 3;
    FILE *fp;

    fp = fopen("COEF.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Allocate memory for n x n matrix
    double **COEF = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        COEF[i] = (double *)malloc(D * sizeof(double));
    }

    // Read values row by row
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < D; j++) {
            if (fscanf(fp, "%lf", &COEF[i][j]) != 1) {
                fprintf(stderr, "Error: Not enough data in file\n");
                return 1;
            }
        }
    }

    fclose(fp);

    FILE *fk;

    fk = fopen("JCOEF.txt", "r");
    if (fk == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Allocate memory for n x n matrix
    int **JCOEF = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        JCOEF[i] = (int *)malloc(D * sizeof(int));
    }

    // Read values row by row
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < D; j++) {
            if (fscanf(fk, "%d", &JCOEF[i][j]) != 1) {
                fprintf(stderr, "Error: Not enough data in file\n");
                return 1;
            }
        }
    }

    fclose(fk);

    get_matrix(COEF, JCOEF, n, D);

}