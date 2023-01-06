#include <stdio.h>

int main(void)
{	
	int H = 0, M = 0;
	scanf_s("%d%d", &H, &M);

	if (M - 45 < 0)
	{
		M = 60 + (M-45);
		--H;
		if (H < 0)
			H = 23;
	}

	else
		M -= 45;

	printf("%d %d", H, M);


	return 0;
}