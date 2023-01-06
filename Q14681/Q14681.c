#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void)
{
	int x, y;
	scanf_s("%d%d", &x, &y);
	if (x > 1000)
		x = 1000;
	if (x < -1000)
		x = -1000;
	if (y > 1000)
		y = 1000;
	if (y < -1000)
		y = -1000;
	if (x == 0 || y == 0)
	{
		printf("%s\n", "This input cannot be accepted");
	}

	if (x > 0)
	{
		if (y > 0)
			printf("%d\n", 1);
		else
			printf("%d\n", 4);
	}
	else
	{
		if (y > 0)
			printf("%d\n", 2);
		else
			printf("%d\n", 3);
	}



	return 0;
}