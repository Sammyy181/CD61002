#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* solve_MR(double** A, double* B, int n){

    double *x = calloc(n, sizeof(double));
    double *residual = calloc(n, sizeof(double));

    int no_iter = 0;
    int i;
    int row, col;
    int stop_iter = 4000;
    double error_margin = 1e-3;

    double Ax_row;
    double alphanum, alphaden, alpha;
    double error;
    double *p = calloc(n, sizeof(double));

    for(row=0; row < n; row++){
            Ax_row = 0;
            for(col=0; col < n; col++){
                Ax_row += A[row][col] * x[col];
            }
            residual[row] = B[row] - Ax_row;
        }

        for(row=0; row<n; row++){
            p[row] = 0;
            for(col=0; col<n; col++){
                p[row] += A[row][col] * residual[col];
            }
        }

    do{
        // Dot Product of p and residual
        alphanum = 0;
        alphaden = 0;

        for(i=0; i<n;i++){
            alphanum += p[i] * residual[i];
            alphaden += p[i] * p[i];
        }

        alpha = alphanum / alphaden;

        for(i=0; i<n;i++){
            x[i] = x[i] + alpha * residual[i];
            residual[i] = residual[i] - alpha * p[i];
        }

        for(row = 0; row < n; row++){
            p[row] = 0;
            for(col=0; col<n; col++){
                p[row] += A[row][col] * residual[col];
            }
        }
        
        error = 0;
        for(i=0; i<n; i++)
            error += residual[i] * residual[i];
        error = sqrt(error);

        no_iter++;
    } while(no_iter < stop_iter && error > error_margin);

    printf("MR converged in %d iterations with error: %e\n", no_iter, error);

    free(residual);
    free(p);
    return x;

}