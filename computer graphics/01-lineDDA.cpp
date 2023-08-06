#include <stdio.h>
#include <graphics.h>
#include <math.h>

void drawLineDDA(int x1, int y1, int x2, int y2)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }

    delay(50000);
    closegraph();
}

int main()
{
    int x1, y1, x2, y2;
    printf("\n****** DDA Line Drawing Algorithm ***********\n");
    printf("\nEnter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    drawLineDDA(x1, y1, x2, y2);

    return 0;
}
