#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findFDM(int n){

    double ** A;
    int size = n * n;
    int i, j;
    A = (double **)calloc(size, sizeof(double *));
    for (i = 0; i < size; i++){
        A[i] = (double *)calloc(size, sizeof(double));
    }
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            if(i == j) A[i][j] = 4.0;
            else if(abs(i-j) == 1) A[i][j] = -1.0;
            else if(abs(i-j) == n) A[i][j] = -1.0;    
        }
    }

    double *b;
    b = (double *)calloc(size, sizeof(double));
    for (i = 0; i < n; i++){
        b[size-i - 1] = 1.0;
    }
    
    // Save matrix A
    FILE *fp1 = fopen("Amatrix_12.txt", "w");
    if (fp1 == NULL) {
        perror("Error opening matrix.txt");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(fp1, "%.1f ", A[i][j]);
        }
        fprintf(fp1, "\n");
    }
    fclose(fp1);

    // Save vector b
    FILE *fp2 = fopen("Bvec_12.txt", "w");
    if (fp2 == NULL) {
        perror("Error opening Bvec.txt");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        fprintf(fp2, "%.4f\n", b[i]);   // one entry per line
    }
    fclose(fp2);

    printf("Matrix and Vector stored");
    
}

int main(){
    int n = 13;
    
    findFDM(n-2);
}

// Spectral radius for n = 13, Spectral Radius is 0.9824
// Spectral radius for n = 26, Spectral Radius is 0.9960
// Spectral radius for n = 51, Spectral Radius is 0.9990