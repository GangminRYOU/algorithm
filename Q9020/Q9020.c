#include <stdio.h>

int isGP(int n)
{
	if(n % 2 == 0)
		for (int i = 2; i < n / 2; ++i)
		{
			if ((n / 2) % i == 0)
				return (0);
		}
	return (1);
}

int FindPreprime(int n)
{
	int i = 0, j = 0;
	n--;
	for (i = n; i >= 2; --i)
	{
		for (j = 2; j < i; ++j)
		{
			if (i % j == 0)
				break;
		}
		if (i == j)
			return (i);
	}
	return (0);
}

int isOtherPrime(int prePrime, int n)
{
	int otherPrime = n - prePrime;
	for (int i = 2; i < otherPrime; ++i)
	{
		if (otherPrime % i == 0)
			return (0);
	}
	return (otherPrime);
}

int main(void)
{
	int nCycle = 0, n = 0, prePrime = 0, otherPrime = 0;
	scanf_s("%d", &nCycle);
	for (int i = 0; i < nCycle; ++i)
	{
		scanf_s("%d", &n);
		if (isGP(n))
			printf("%d %d\n", n / 2, n / 2);
		else
		{
			prePrime = n / 2;
			while (1)
			{
				prePrime = FindPreprime(prePrime);
				if (otherPrime = isOtherPrime(prePrime, n))
				{
					printf("%d %d\n", prePrime, otherPrime);
					break;
				}
			}
		}

	}
	return (0);
}
