#include <stdio.h>
#include <math.h>
#include <graphics.h>

void drawEllipse(int centerX, int centerY, int semiMajorAxis, int semiMinorAxis)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int aSq = semiMajorAxis * semiMajorAxis;
    int bSq = semiMinorAxis * semiMinorAxis;

    int x = 0;
    int y = semiMinorAxis;

    int decision = bSq + (aSq * (0.25 - semiMinorAxis));

    while ((2 * bSq * x) <= (2 * aSq * y))
    {
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);

        x++;

        if (decision < 0)
        {
            decision += (2 * bSq * x) + bSq;
        }
        else
        {
            y--;
            decision += (2 * bSq * x) - (2 * aSq * y) + bSq;
        }
    }

    decision = bSq * (x + 0.5) * (x + 0.5) + (aSq * (y - 1) * (y - 1)) - (aSq * bSq);

    while (y >= 0)
    {
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);

        y--;

        if (decision > 0)
        {
            decision += aSq - (2 * aSq * y);
        }
        else
        {
            x++;
            decision += (2 * bSq * x) - (2 * aSq * y) + aSq;
        }
    }

    delay(50000);
    closegraph();
}

int main()
{
    int centerX, centerY, semiMajorAxis, semiMinorAxis;
    printf("********* ELLIPSE DRAWING DIRECT METHOD ALGORITHM ********\n\n");
    printf("Enter the center coordinates of the ellipse (centerX, centerY): ");
    scanf("%d %d", &centerX, &centerY);
    printf("Enter the semi-major axis length: ");
    scanf("%d", &semiMajorAxis);
    printf("Enter the semi-minor axis length: ");
    scanf("%d", &semiMinorAxis);

    drawEllipse(centerX, centerY, semiMajorAxis, semiMinorAxis);

    return 0;
}
