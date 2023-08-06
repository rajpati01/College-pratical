#include <stdio.h>
#include <graphics.h>
#include <conio.h>
int main()
{
    int gd = DETECT, gm;
    int x, y, x1, y1, x2, y2, shear_f;
    initgraph(&gd, &gm, NULL);
    printf("\nplease enter first coordinate = ");
    scanf("%d %d", &x, &y);
    printf("please enter second coordinate = ");
    scanf("%d %d", &x1, &y1);
    printf("please enter third coordinate = ");
    scanf("%d %d", &x2, &y2);
    printf("please enter shearing factor x = ");
    scanf("%d", &shear_f);
    cleardevice();
    line(x, y, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x, y);

    setcolor(WHITE);
    x = x + y * shear_f;
    x1 = x1 + y1 * shear_f;
    x2 = x2 + y2 * shear_f;

    line(x, y, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x, y);
    getch();
    closegraph();

    return 0;
}