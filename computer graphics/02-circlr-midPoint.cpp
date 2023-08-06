#include <stdio.h>
#include <graphics.h>

void drawCircle(int centerX, int centerY, int radius)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x = 0;
    int y = radius;
    int decision = 1 - radius;

    while (x <= y)
    {
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
        putpixel(centerX + y, centerY + x, WHITE);
        putpixel(centerX - y, centerY + x, WHITE);
        putpixel(centerX + y, centerY - x, WHITE);
        putpixel(centerX - y, centerY - x, WHITE);

        x++;

        if (decision < 0)
        {
            decision += 2 * x + 1;
        }
        else
        {
            y--;
            decision += 2 * (x - y) + 1;
        }
    }

    delay(50000);
    closegraph();
}

int main()
{
    int centerX, centerY, radius;
    printf("********* MID POINT Circle drawing algorithm ********\n\n");
    printf("Enter the center coordinates of the circle (centerX, centerY): ");
    scanf("%d %d", &centerX, &centerY);
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);

    drawCircle(centerX, centerY, radius);

    return 0;
}
