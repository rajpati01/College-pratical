#include <stdio.h>
#include <cmath>
#include <graphics.h>

void drawEllipse(int centerX, int centerY, int semiMajorAxis, int semiMinorAxis)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x = 0;
    int y = semiMinorAxis;
    int aSq = semiMajorAxis * semiMajorAxis;
    int bSq = semiMinorAxis * semiMinorAxis;

    int twoASq = 2 * aSq;
    int twoBSq = 2 * bSq;
    int xEnd = round(aSq / sqrt(aSq + bSq));
    int px = 0;
    int py = twoASq * y;
    // Region 1
    int p = round(bSq - aSq * semiMinorAxis + 0.25 * aSq);
    while (px <= py)
    {
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        x++;
        px += twoBSq;
        if (p < 0)
        {
            p += bSq + px;
        }
        else
        {
            y--;
            py -= twoASq;
            p += bSq + px - py;
        }
    }
    // Region 2
    p = round(bSq * (x + 0.5) * (x + 0.5) + aSq * (y - 1) * (y - 1) - aSq * bSq);
    while (y >= 0)
    {
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        y--;
        py -= twoASq;
        if (p > 0)
        {
            p += aSq - py;
        }
        else
        {
            x++;
            px += twoBSq;
            p += aSq - py + px;
        }
    }
    delay(50000);
    closegraph();
}

int main()
{
    int centerX, centerY, semiMajorAxis, semiMinorAxis;
    printf("\n********* ELLIPSE DRAWING MID POINT ALGORITHM ********\n\n");
    printf("Enter the center coordinates of the ellipse (centerX, centerY): ");
    scanf("%d %d", &centerX, &centerY);
    printf("Enter the semi-major axis length: ");
    scanf("%d", &semiMajorAxis);
    printf("Enter the semi-minor axis length: ");
    scanf("%d", &semiMinorAxis);

    drawEllipse(centerX, centerY, semiMajorAxis, semiMinorAxis);

    return 0;
}
