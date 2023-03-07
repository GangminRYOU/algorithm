#include <stdio.h>

#define WHITE 0
#define BLACK 1
#define YELLOW 2

int screen[10][10] = {0};

void initScreen(void)
{
	int i = 0, j = 0;
	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			if (i == 2 && j >= 3 && j <= 6)
				screen[i][j] = 0;
			else if (i == 3 && j >= 4 && j <= 6)
				screen[i][j] = 0;
			else if (i == 4 && j >= 4 && j <= 6)
				screen[i][j] = 0;
			else if (i == 5 && j >= 4 && j <= 7)
				screen[i][j] = 0;
			else if (j == 4 && i >= 6 && i <= 8)
				screen[i][j] = 0;
			else
				screen[i][j] = 2;
		}
	}
}

char read_pixel(int x, int y)
{
	return screen[x][y];
}

void write_pixel(int x, int y, int color)
{
	screen[x][y] = color;
}

void print_map(void)
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			printf("%d ", screen[i][j]);
		}
		putchar('\n');
	}
}		

void flood_fill(int x, int y)
{
	if (read_pixel(x, y) == WHITE)
	{
		write_pixel(x, y, BLACK);
		flood_fill(x + 1, y);
		flood_fill(x, y + 1);
		flood_fill(x - 1, y);
		flood_fill(x, y - 1);
	}
}

int main(void)
{
	initScreen();
	flood_fill(5, 4);
	print_map();
	return (0);
}
