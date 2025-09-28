# Assignment 2
**CD61002: High Performance Scientific Computing**  
**Samarth G**  
**23EC30042**   

## Deriving the Finite Difference Matrix

Used the formula:

\[
\frac{\partial^2 u}{\partial x^2} + \frac{\partial^2 u}{\partial y^2} 
\approx \frac{u_{i+1,j} - 2u_{i,j} + u_{i-1,j}}{h^2} 
+ \frac{u_{i,j+1} - 2u_{i,j} + u_{i,j-1}}{h^2}
\]
