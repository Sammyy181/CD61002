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
