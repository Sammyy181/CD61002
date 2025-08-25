# CD61002

High Performance Scientific Computing Assignments for Autumn 2025 and my solution :)

## Assignment 1

To get the `KMat.txt` and `Fvec.txt` files, move the corresponding `.msh` files to the right directory and run:

```bash
gcc mshtofem.c -o mshtofem
./mshtofem <Prefix of your .msh file>
```

Once you get the elements and nodes from here, change the lines from `fem.c` with the correct file names and then run:

```bash
gcc fem.c -o fem
./fem
```

You can use these files using `matrixSolver.c` to get the solution vector **x** for **Ax = B**. `matrixSolver.c` is currently set to SOR. You can change that according to your requirement.
