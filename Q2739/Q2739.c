#include <stdio.h>

int main(void)
{
	int N = 0, i =0;
	
	scanf_s("%d", &N);


	for (i = 1; i < 10; ++i)
		printf("%d * %d = %d\n", N, i, N * i);

	return 0;
}