% Consider the Matrix Equation Ax = b
Kmat = readmatrix("Kmat_160.txt");
% b = readmatrix("Fvec_40.txt");

% Reshape to the correct dimension
A = reshape(Kmat, [140,140]);

D = diag(diag(A));
E = -1 * tril(A, -1);
F = -1 * triu(A, 1);

% Iteration Matrix for Jacobi
G = inv(D) * (E + F);

% Iteration Matrix for Gauss-Seidel
% G = inv(D - E) * F;

% Iteration Matrix for Successive Over Relaxation given an omega
%{
omega = 1.8;
G = (D - omega*E) \ (omega*F + (1-omega)*D); 
%}

% Get the Eigenvalues and the spectral radius
e = eig(G);
rho = max(abs(e));
tau = -1 * log(rho);