#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SuccessiveOverRelaxation.c"  
#include "sDescent.c" 
#include "CG.c"
#include "BICGSTAB.c"

int main() {
    int n, i, j;
    FILE *fp, *ff;

    // 121, 576, 2401
    n = 2401;
    double *B = malloc(n * sizeof(double));

    // Read K matrix
    fp = fopen("Amatrix_50.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Allocate memory for n x n matrix
    double **A = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
    }

    // Read values row by row
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fscanf(fp, "%lf", &A[i][j]) != 1) {
                fprintf(stderr, "Error: Not enough data in file\n");
                return 1;
            }
        }
    }

    fclose(fp);

    // Read F vector
    ff = fopen("Bvec_50.txt", "r");
    for (i = 0; i < n; i++)
        fscanf(ff, "%lf", &B[i]);
    fclose(ff);

    // Solve
    //double *U = solve_SOR(A, B, n, 0.999);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    double *U = solve_SOR(A, B, n, 0.999);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU runtime for SOR: %e seconds\n", cpu_time_used);

    // Print solution
    //printf("\nSolution vector U:\n");
    /*for (i = 0; i < n; i++)
        printf("U[%d] = %lf\n", i, U[i]); */

    // Cleanup
    for (i = 0; i < n; i++) free(A[i]);
    free(A);
    free(B);
    free(U);

    return 0;
}