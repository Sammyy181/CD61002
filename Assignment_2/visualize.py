import numpy as np
import matplotlib.pyplot as plt

# Load matrix and vector
A = np.loadtxt("Amatrix_12.txt")
b = np.loadtxt("Bvec_12.txt")

print("Matrix A shape:", A.shape)
print("Vector b shape:", b.shape)

# Quick visualization: heatmap of A
plt.imshow(A, cmap="viridis")
plt.colorbar(label="Value")
plt.title("Finite Difference Matrix A")
plt.show()

# If you want to visualize b
plt.plot(b, marker="o")
plt.title("Vector b")
plt.show()
