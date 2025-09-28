#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double* solve_SOR(double **A, double *B, int n, double w){

    double *x_k = calloc(n, sizeof(double));
    double *x_k1 = calloc(n, sizeof(double));

    int no_iter = 0, row_op = 0, column_op = 0;
    int i;
    int stop_iter = 250;
    double error_margin = 1e-4, error = 0;
    double max_error, row_sum;

    for(i=0;i<n;i++){
        if(fabs(A[i][i]) < 1e-10){
            printf("Error - Zero Diagonal Element found in Matrix");
            free(x_k);
            free(x_k1);
            return NULL;
        }
    }

    do
    {
        for(i=0; i<n; i++)
            x_k[i] = x_k1[i];
        
        max_error = 0;
        
        for(row_op = 0; row_op < n; row_op++)
        {
            row_sum = 0;

            for(column_op = 0; column_op < n; column_op++){
                if(column_op != row_op) row_sum += A[row_op][column_op] * x_k1[column_op];
            }

            x_k1[row_op] = (w * (B[row_op] - row_sum)/A[row_op][row_op]) + ((1-w)*x_k1[row_op]);
            
        }

        for(i = 0; i < n; i++){
            error = fabs(x_k1[i] - x_k[i]);
            if (error > max_error) max_error = error;
        }

        no_iter++;

        printf("Iteration No %d\t|\t", no_iter);
        printf("Error - %.4f\n", max_error);
        if(no_iter <= 11 && no_iter >=9){
            for(i = 0; i < n; i++){
                printf("Difference between iterations at index %d = %f\n", i, (x_k1[i] - x_k[i]));
            }
        }   

    } while (max_error > error_margin && no_iter < stop_iter);

    printf("Number of Iterations for SOR with w = %.1f - %d", w, no_iter);
    return x_k1;
}