#include <stdio.h>
#include <conio.h>
#include <math.h>
float f(float x)
{
    float y;
    y = pow(x, 2) + x - 2;
    return y;
}
void main()
{
    float x1, x2, x0, error = 0.0001;
    int i = 0;
    printf("\nEnter two initial guess:");
    scanf("%f%f", &x1, &x2);
    do
    {
        x0 = x1 - (f(x1) * (x2 - x1)) / (f(x2) - f(x1));
        x2 = x1;
        x1 = x0;
        i++;
    } while (fabs(f(x0)) > error);
    printf("\nRoot=%f", x0);
    printf("\nNumber of iteration=%d", i);
    getch();
}