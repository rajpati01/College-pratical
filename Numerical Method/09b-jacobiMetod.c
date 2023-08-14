/* Arrange system of linear equations in
diagonally dominant form and convert the
1
st equation in tems of 1st variable (f1), 2nd
equation in terms of 2nd variable (f2) and so
on */
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define f1(x, y, z) (17 - y + 2 * z) / 20
#define f2(x, y, z) (-18 - 3 * x + z) / 20
#define f3(x, y, z) (25 - 2 * x + 3 * y) / 20

/* Main function */
int main()
{
    float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e;
    int count = 1;

    printf("\nEnter tolerable error: ");
    scanf("%f", &e);

    printf("\nCount\tx\ty\tz\n");
    do
    {
        /* Calculation */
        x1 = f1(x0, y0, z0);
        y1 = f2(x0, y0, z0);
        z1 = f3(x0, y0, z0);
        printf("%d\t%0.4f\t%0.4f\t%0.4f\n", count, x1, y1, z1);

        /* Error */
        e1 = fabs(x0 - x1);
        e2 = fabs(y0 - y1);
        e3 = fabs(z0 - z1);

        count++;

        /* Set value for next iteration */
        x0 = x1;
        y0 = y1;
        z0 = z1;
    } while (e1 > e && e2 > e && e3 > e);

    printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n", x1, y1, z1);

    getch();
    return 0;
}