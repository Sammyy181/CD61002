# Assignment 2
**CD61002: High Performance Scientific Computing**  
**Samarth G**  
**23EC30042**   

## Deriving the Finite Difference Matrix

Used the formula:

$$
\frac{\partial^2 u}{\partial x^2} + \frac{\partial^2 u}{\partial y^2}
\approx
\frac{u_{i+1,j} - 2u_{i,j} + u_{i-1,j}}{h^2}
+
\frac{u_{i,j+1} - 2u_{i,j} + u_{i,j-1}}{h^2}
$$

Five-point stencil form (Poisson's equation):

$$
-4u_{i,j} + u_{i+1,j} + u_{i-1,j} + u_{i,j+1} + u_{i,j-1} = h^2 f_{i,j}
$$

As only interior points were required for the matrix, given the distance as 0.02, 0.04 and 0.08, the number of interior points were given by (n-2) squared. Thus, the the matrices were of 2401x2401, 576x576 and 121x121 size respectively.

It resulted in a pentadiagonal symmetric matrix.

## Successive Over Relaxation (Optimum)

For Successive Over Relaxation, the values were as follows:

| Step Size | Optimum ω | Number of Iterations | CPU Time (in s) |
|-----------|-----------|-----------------------|-----------------|
| 0.08      | 0.9824    | 37                    | 3.7e-3          |
| 0.04      | 0.9960    | 73                    | 9.5e-2          |
| 0.02      | 0.9990    | 135                   | 2.73            |

## Steepest Descent

For Steepest Descent, the values were as follows:

| Step Size | Number of Iterations | CPU Time (in s) |
|-----------|-----------------------|-----------------|
| 0.08      | 348                   | 5.9e-2          |
| 0.04      | 1948                  | 4.52            |
| 0.02      | 7163                  | 433.9           |

## Minimum Residual

For Minimum Residual (MR), the values are as follows:

| Step Size | Number of Iterations | CPU Time (in s) |
|-----------|-----------------------|-----------------|
| 0.08      | 330                   | 2.4e-2          |
| 0.04      | 1282                  | 1.49            |
| 0.02      | 4000                  | 82.4            |

## Conjugate Gradient

For Conjugate Gradient (CG), the values are as follows:

| Step Size | Number of Iterations | CPU Time (in s) |
|-----------|-----------------------|-----------------|
| 0.08      | 31                    | 2.9e-3          |
| 0.04      | 64                    | 8.5e-2          |
| 0.02      | 123                   | 2.52            |

## BICGSTAB

For Biconjugate Gradient Stabilized (BICGSTAB) the values are as follows:

| Step Size | Number of Iterations | CPU Time (in s) |
|-----------|-----------------------|-----------------|
| 0.08      | 81                    | 1.8e-2          |
| 0.04      | 150                   | 3.6e-1          |
| 0.02      | 150                   | 6.12            |

For each of the methods, an error margin of 1e-4 was considered, and the L2 norm was used. 