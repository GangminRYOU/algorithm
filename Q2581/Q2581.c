#include <stdio.h>

int isPrime(int N)
{
	if (N == 1)
		return (0);
	for (int i = 2; i <= N / i; ++i)
	{
		if (N % i == 0)
			return (0);
	}
	return (1);
}

int main(void)
{
	int M = 0, N = 0, nSum = 0, nFirst_prime = 0;
	int i = 0;
	scanf_s("%d%d", &M, &N);
	for (i = M; i <= N; ++i)
	{
		if (isPrime(i))
		{
			nFirst_prime = i;
			nSum += i;
			break;
		}
	}
	++i;
	while (i <= N)
	{
		if (isPrime(i))
			nSum += i;
		++i;
	}
	if (nFirst_prime == 0)
		puts("-1\n");
	else
		printf("%d\n%d\n", nSum, nFirst_prime);
	
	return (0);
}
