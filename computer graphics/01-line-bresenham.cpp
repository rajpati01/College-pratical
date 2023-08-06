#include <stdio.h>
#include <graphics.h>
#include <math.h>
void drawLineBresenham(int x1, int y1, int x2, int y2)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1;
    int y = y1;
    int xIncrement = (x1 < x2) ? 1 : -1;
    int yIncrement = (y1 < y2) ? 1 : -1;
    int interchange = 0;
    if (dy > dx)
    {
        int temp = dx;
        dx = dy;
        dy = temp;
        interchange = 1;
    }
    int error = 2 * dy - dx;
    for (int i = 0; i <= dx; i++)
    {
        putpixel(x, y, WHITE);
        while (error >= 0)
        {
            if (interchange)
                x += xIncrement;
            else
                y += yIncrement;
            error -= 2 * dx;
        }
        if (interchange)
            y += yIncrement;
        else
            x += xIncrement;
        error += 2 * dy;
    }
    delay(5000);
    closegraph();
}
int main()
{
    int x1, y1, x2, y2;
    printf("******* BRESENHAM'S LINE DRAWING ALGORITHM *****\n\n");
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    drawLineBresenham(x1, y1, x2, y2);
    return 0;
}
