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

## 
