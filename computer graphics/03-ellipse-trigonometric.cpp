#include <stdio.h>
#include <math.h>
#include <graphics.h>

void drawEllipse(int centerX, int centerY, int semiMajorAxis, int semiMinorAxis)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    float angle = 0;
    float angleIncrement = 0.01;

    while (angle <= 2 * M_PI)
    {
        int x = centerX + round(semiMajorAxis * cos(angle));
        int y = centerY + round(semiMinorAxis * sin(angle));

        putpixel(x, y, WHITE);

        angle += angleIncrement;
    }

    delay(50000);
    closegraph();
}

int main()
{
    int centerX, centerY, semiMajorAxis, semiMinorAxis;
    printf("********* ELLIPSE DRAWING TRIGONOMETRIC METHOD ALGORITHM ********\n\n");

    printf("Enter the center coordinates of the ellipse (centerX, centerY): ");
    scanf("%d %d", &centerX, &centerY);
    printf("Enter the semi-major axis length: ");
    scanf("%d", &semiMajorAxis);
    printf("Enter the semi-minor axis length: ");
    scanf("%d", &semiMinorAxis);

    drawEllipse(centerX, centerY, semiMajorAxis, semiMinorAxis);

    return 0;
}
