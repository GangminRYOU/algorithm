#include <stdio.h>

int main(void)
{
	int N = 0;
	scanf_s("%d", &N);


	for (int i = N-1; i >= 0; --i)
	{
		for (int j = 0; j < N; ++j)
			if (j < i)
				putchar(' ');
			else
				putchar('*');
		putchar('\n');
	}

	return 0;

}