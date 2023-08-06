// WAP for following 2D-geometrical transformations.
/* Translattion, Rotation, Rotation about arbitriary point, Scaling , Reflection, X-shear, Y-shear*/
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void translation(int, int, int, int, int, int);
void rotation(int, int, int, int, int);
void rotationArbitrary(int, int, int, int, int, int, int);
void scaling(int, int, int, int, int, int);

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	int ch;
	printf("\n\n 1. Translation \n 2. Rotation \n 3. Rotation about arbitrary point \n 4. Scaling \n");
	printf("Enter your Choice (1,2,3,4): ");
	scanf("%d", &ch);

	if (ch == 1)
		translation(100, 200, 200, 400, 50, 10);
	else if (ch == 2)
		rotation(50, 200, 50, 300, -45);
	else if (ch == 3)
		rotationArbitrary(50, 100, 50, 300, 10, 20, -45);
	else if (ch == 4)
		scaling(50, 100, 65, 200, 5, 2);
	else
		printf("\n\nInvalid Entry");
	getch();
	return 0;
}

void translation(int x1, int y1, int x2, int y2, int tx, int ty)
{
	outtextxy(x1 - 20, y1 - 20, "Origninal Line");
	line(x1, y1, x2, y2);
	int x3 = x1 + tx, y3 = y1 + ty;
	int x4 = x2 + tx, y4 = y2 + ty;
	outtextxy(x4 + 2, y4 + 2, "translated Line");
	line(x3, y3, x4, y4);
}

void rotation(int x1, int y1, int x2, int y2, int ang)
{
	outtextxy(x1 - 20, y1 - 20, "Origninal Line");

	line(x1, y1, x2, y2);

	int x3 = x1 * cos(ang) - y1 * sin(ang);
	int y3 = x1 * sin(ang) + y1 * cos(ang);

	int x4 = x2 * cos(ang) - y2 * sin(ang);
	int y4 = x2 * sin(ang) + y2 * cos(ang);

	outtextxy(x4 + 2, y4 + 2, "rotated Line");
	line(x3, y3, x4, y4);
}

void rotationArbitrary(int x1, int y1, int x2, int y2, int xr, int yr, int ang)
{
	outtextxy(x1 - 20, y1 - 20, "Origninal Line");

	line(x1, y1, x2, y2);

	int x3 = xr + (x1 - xr) * cos(ang) - (y1 - yr) * sin(ang);
	int y3 = yr + (x1 - xr) * sin(ang) + (y1 - yr) * cos(ang);

	int x4 = xr + (x2 - xr) * cos(ang) - (y2 - yr) * sin(ang);
	int y4 = yr + (x2 - xr) * sin(ang) + (y2 - yr) * cos(ang);

	outtextxy(x4 + 2, y4 + 2, "rotated Line about arbitrary point");
	line(x3, y3, x4, y4);
}

void scaling(int x1, int y1, int x2, int y2, int sx, int sy)
{
	outtextxy(x1 - 20, y1 - 20, "Origninal Line");
	line(x1, y1, x2, y2);
	int x3 = x1 * sx, y3 = y1 * sy;
	int x4 = x2 * sx, y4 = y2 * sy;
	outtextxy(x4 + 2, y4 + 2, "translated Line");
	line(x3, y3, x4, y4);
}