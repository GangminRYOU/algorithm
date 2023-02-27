#include <stdio.h>

int CheckPerfect(int* nFactors, int n)
{
	int nSum = 0, i = 0;
	while (nFactors[i] != 0)
	{
		nSum += nFactors[i];
		++i;
	}
	if (nSum == n)
		return (1);
	return (0);
}



int main(void)
{
	int n = 0, i = 1, cnt = 0;
	int nFactors[100] = { 0 };
	
	while (1)
	{
		scanf_s("%d", &n);
		if (n == -1)
			return (0);
		for (i = 1; i < n; ++i)
		{
			if (n % i == 0)
			{
				nFactors[cnt] = i;
				++cnt;
			}
		}
		cnt = 1;
		if (CheckPerfect(nFactors, n))
		{
			printf("%d = 1", n);
			while (nFactors[cnt] != 0)
			{
				printf(" + %d", nFactors[cnt]);
				++cnt;
			}
			putchar('\n');
			cnt = 0;
		}
		else
			printf("%d is NOT perfect.\n", n);
		while (nFactors[cnt] != 0)
		{
			nFactors[cnt] = 0;
			++cnt;
		}
		cnt = 0;
	}
	return (0);
}
