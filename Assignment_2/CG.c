#include <stdio.h>
#include <stdlib.h>

double* iterCG(double** A, double*b, int n){

    double* x = calloc(n, sizeof(double));
    double *p = calloc(n, sizeof(double));
    double *residual = calloc(n, sizeof(double));
    double *Ap = calloc(n, sizeof(double));

    int i, j;
    int iter_no = 0, stop_iter;
    stop_iter = 150;
    double tolerance = 1e-4;
    double error;
    
    double alphanum, alphaden, alpha;
    double betanum, betaden, beta;

    for(i = 0; i < n; i++){
        Ap[i] = 0;

        for(j = 0; j < n; j++){
            Ap[i] += A[i][j] * x[j];
        }
        residual[i] = b[i] - Ap[i];
        p[i] = residual[i];
    }

    do{
        alphanum = 0;
        alphaden = 0;
        betanum = 0;
        betaden = 0;

        for(i=0; i<n; i++){
            Ap[i] = 0;
            alphanum += residual[i] * residual[i];
            for(j = 0; j < n; j++){
                Ap[i] += A[i][j] * p[j];
            }
            alphaden += p[i] * Ap[i];
        }

        alpha = alphanum / alphaden;
        betaden = alphanum;

        for(i = 0; i < n; i++){
            x[i] += alpha * p[i];
            residual[i] -= alpha * Ap[i];
            betanum += residual[i] * residual[i];
        }

        beta = betanum / betaden;

        for(i = 0; i < n; i++){
            p[i] = residual[i] + (beta * p[i]);
        }

        error = sqrt(betanum);
        iter_no++;
        printf("Iteration %d: Error = %e\n", iter_no, error);
    }while(iter_no < stop_iter && error > tolerance);

    printf("Converged in %d iterations with error %e\n", iter_no, error);
    return x;
}