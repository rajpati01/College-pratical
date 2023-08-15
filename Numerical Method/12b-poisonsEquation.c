#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NX 50 // Number of grid points in x-direction
#define NY 50 // Number of grid points in y-direction
#define L 1.0 // Length of the domain in x and y directions
#define W 1.0 // Width of the domain in x and y directions
#define DX (L / (NX - 1))
#define DY (W / (NY - 1))
#define MAX_ITER 10000
#define TOLERANCE 1e-6

// Function to initialize the boundary conditions
void initialize_boundary(double u[][NY])
{
    // Set boundary conditions (u = 0 on all boundaries)
    for (int i = 0; i < NX; i++)
    {
        u[i][0] = 0.0;
        u[i][NY - 1] = 0.0;
    }
    for (int j = 0; j < NY; j++)
    {
        u[0][j] = 0.0;
        u[NX - 1][j] = 0.0;
    }
}

// Function to perform the finite difference iteration
void solve_poisson_equation(double u[][NY], double f[][NY])
{
    double u_old[NX][NY];

    for (int iter = 0; iter < MAX_ITER; iter++)
    {
        // Copy the current solution to u_old
        for (int i = 0; i < NX; i++)
        {
            for (int j = 0; j < NY; j++)
            {
                u_old[i][j] = u[i][j];
            }
        }

        // Update the solution using finite difference method
        for (int i = 1; i < NX - 1; i++)
        {
            for (int j = 1; j < NY - 1; j++)
            {
                u[i][j] = 0.25 * (u_old[i + 1][j] + u_old[i - 1][j] + u_old[i][j + 1] + u_old[i][j - 1] - DX * DY * f[i][j]);
            }
        }

        // Check for convergence
        double max_diff = 0.0;
        for (int i = 0; i < NX; i++)
        {
            for (int j = 0; j < NY; j++)
            {
                double diff = fabs(u[i][j] - u_old[i][j]);
                if (diff > max_diff)
                {
                    max_diff = diff;
                }
            }
        }

        if (max_diff < TOLERANCE)
        {
            printf("Converged after %d iterations.\n", iter + 1);
            break;
        }
    }
}

int main()
{
    double u[NX][NY]; // Electric potential
    double f[NX][NY]; // Source term

    // Initialize the source term
    for (int i = 0; i < NX; i++)
    {
        for (int j = 0; j < NY; j++)
        {
            f[i][j] = 1.0; // Constant source term for simplicity
        }
    }

    // Initialize boundary conditions
    initialize_boundary(u);

    // Solve the Poisson equation
    solve_poisson_equation(u, f);

    // Print the solution
    printf("Electric Potential:\n");
    for (int j = NY - 1; j >= 0; j--)
    {
        for (int i = 0; i < NX; i++)
        {
            printf("%.6f ", u[i][j]);
        }
        printf("\n");
    }

    return 0;
}
