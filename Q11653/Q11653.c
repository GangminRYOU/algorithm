#include <stdio.h>

void recur(int N, int i)
{
	if (i * i > N)
	{
		printf("%d\n", N);
		return ;
	}
	if (N % i == 0)
	{
		printf("%d\n", i);
		recur(N / i, i);
	}
	else
		recur(N, i + 1);
}


int main(void)
{
	int N = 0;
	scanf_s("%d", &N);
	if (N == 1)
		return (0);
	recur(N, 2);
}
