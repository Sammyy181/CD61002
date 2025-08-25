#include <stdio.h>
#include <stdlib.h>
#include "SuccessiveOverRelaxation.c"   

int main() {
    int n, i, j;
    FILE *fk, *ff;

    // Read system size
    fk = fopen("80_nodes/kinfo_80.txt", "r");
    fscanf(fk, "%d", &n);
    fclose(fk);

    // Allocate
    double **A = malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) A[i] = malloc(n * sizeof(double));
    double *B = malloc(n * sizeof(double));

    // Read K matrix
    fk = fopen("80_nodes/Kmat_80.txt", "r");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            fscanf(fk, "%lf", &A[i][j]);
    fclose(fk);

    // Read F vector
    ff = fopen("80_nodes/Fvec_80.txt", "r");
    for (i = 0; i < n; i++)
        fscanf(ff, "%lf", &B[i]);
    fclose(ff);

    // Solve
    double *U = solve_SOR(A, B, n, 1.8);

    // Print solution
    printf("\nSolution vector U:\n");
    for (i = 0; i < n; i++)
        printf("U[%d] = %lf\n", i, U[i]);

    // Cleanup
    for (i = 0; i < n; i++) free(A[i]);
    free(A);
    free(B);
    free(U);

    return 0;
}
