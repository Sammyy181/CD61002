#include <stdio.h>
#include <stdlib.h>

double* iterBICGSTAB(double** A, double* b, int n){

    double* x = calloc(n, sizeof(double));
    double* residual = calloc(n, sizeof(double));
    double* residual_ = calloc(n, sizeof(double));
    double *p = calloc(n, sizeof(double));
    double *s = calloc(n, sizeof(double));
    double* As = calloc(n, sizeof(double));
    double* Ap = calloc(n, sizeof(double));

    int i, j;
    double alpha, beta, omega;
    double alphanum, alphaden, betanum, betaden, omeganum, omegaden;
    int iter_no = 0, stop_iter = 150;
    double error = 0, tolerance = 1e-4;

    for(i = 0; i < n; i++){
        Ap[i] = 0;
        for(j = 0; j < n; j++){
            Ap[i] += A[i][j] * x[j];
        }
        residual[i] = b[i] - Ap[i];
        residual_[i] = residual[i];
        p[i] = residual[i];
    }

    do{
        alphanum = 0;
        alphaden = 0;

        omeganum = 0;
        omegaden = 0;

        betanum = 0;
        betaden = 0;

        for(i = 0; i < n; i++){
            Ap[i] = 0;
            for(j = 0; j < n; j++){
                Ap[i] += A[i][j] * p[j];
            }

            alphanum += residual[i] * residual_[i];
            alphaden += Ap[i] * residual_[i];
        }

        alpha = alphanum / alphaden;

        for(i = 0; i < n; i++){
            s[i] = residual[i] -  (alpha * Ap[i]);
            As[i] = 0;
            for(j = 0; j < n; j++){
                As[i] += A[i][j] * s[j];
            }

            omeganum += As[i] * s[i];
            omegaden += As[i] * As[i];
        }

        omega = omeganum / omegaden;

        for(i = 0; i < n; i++){
            x[i] += (alpha * p[i]) + (omega * s[i]);
            betaden += residual[i] * residual_[i];
            residual[i] = s[i] - (omega * As[i]);
            betanum += residual[i] * residual_[i];
        }

        beta = (betanum * alpha) / (betaden * omega);

        for(i = 0; i < n; i++){
            p[i] = residual[i] + (beta * (p[i] - (omega * Ap[i])));
        }

        error = 0;
        for(i = 0; i < n; i++){
            error += residual[i] * residual[i];
        }
        error = sqrt(error);

        iter_no++;
        printf("Iteration %d: Error = %e\n", iter_no, error);

    }while(iter_no < stop_iter && error > tolerance);

    printf("Converged in %d iterations with error %e\n", iter_no, error);
    return x;
}