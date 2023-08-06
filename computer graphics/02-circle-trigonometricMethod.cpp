#include <stdio.h>
#include <graphics.h>
#include <math.h>

void drawCircle(int centerX, int centerY, int radius)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    float angle = 0;
    float angleIncrement = 0.01;
    while (angle <= 2 * M_PI)
    {
        int x = centerX + round(radius * cos(angle));
        int y = centerY + round(radius * sin(angle));

        putpixel(x, y, WHITE);
        angle += angleIncrement;
    }

    delay(50000);
    closegraph();
}

int main()
{
    int centerX, centerY, radius;
    printf("\n******* CIRCLE DRAWING TRIGONOMETRIC METHOD ALGORITHM *****\n\n");
    printf("Enter the center coordinates of the circle (centerX, centerY): ");
    scanf("%d %d", &centerX, &centerY);
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);

    drawCircle(centerX, centerY, radius);

    return 0;
}
