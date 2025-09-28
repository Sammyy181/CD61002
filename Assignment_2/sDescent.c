#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* solve_StepDes(double** A, double* B, int n){

    double *x = calloc(n, sizeof(double));
    double *residual = calloc(n, sizeof(double));

    int no_iter;
    int i;
    int row, col;
    int stop_iter = 8000;
    double error_margin = 1e-4;

    double Ax_row;
    double* P = calloc(n, sizeof(double));
    double alphanum, alphaden, alpha;
    double error;

    for(i=0;i<n;i++){
        if(fabs(A[i][i]) < 1e-10){
            printf("Error - Zero Diagonal Element found in Matrix\n");
            printf("Diagonal Element is at: %d, %d",i, i);
            free(x);
            return NULL;
        }
    }

    do{
        // Dot product of A and x
        alphanum = 0;
        alphaden = 0;
        for(i=0; i<n; i++) P[i] = 0;

        for(row=0; row < n; row++){
            Ax_row = 0;
            for(col=0; col < n; col++){
                Ax_row += A[row][col] * x[col];
            }
            residual[row] = B[row] - Ax_row;
        }

        for(i=0; i<n; i++){
            alphanum += residual[i] * residual[i];
        }

        for(row=0; row<n; row++){
            for(col=0; col<n; col++){
                P[row] += A[row][col] * residual[col];
            }
        }

        for(i=0; i<n; i++){
            alphaden += residual[i] * P[i];
        }

        alpha = alphanum / alphaden;

        for(i=0; i<n; i++){
            x[i] = x[i] + alpha * residual[i];
        }

        error = sqrt(alphanum);
        if(no_iter % 100 == 0){
            printf("Iteration No %d\t|\t", no_iter+1);
            printf("Error - %.4f\n", error);
        }

        no_iter++;

    } while(no_iter < stop_iter && error > error_margin);

    printf("Converged in %d iterations with error %e\n", no_iter, error);
    free(residual);
    free(P);
    return x;
}