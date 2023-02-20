#include <stdio.h>

int main(void)
{
	int T = 0, H = 0, W = 0, N = 0;
	int Y = 0, XX = 0;
	scanf_s("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		scanf_s("%d %d %d", &H, &W, &N);
		if (N % H == 0)
		{
			XX = N / H;
			Y = H;
			printf("%d", Y);
			if (XX < 10)
				printf("0%d\n", XX);
			else
				printf("%d\n", XX);
		}
		else
		{
			XX = N / H + 1;
			Y = N % H;
			printf("%d", Y);
			if (XX < 10)
				printf("0%d\n", XX);
			else
				printf("%d\n", XX);
		}
	}

	return (0);
}
