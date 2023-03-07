#include <stdio.h>

int main(void)
{
	int n = 0, k = 0;
	int nCoeff = 0;
	scanf_s("%d%d", &n, &k);
	int i = 0;
	int j = 0;
	if (n == k)
		nCoeff = 1;
	while (n >= k)
	{
		i = n - 1;
		j = k - 1;
		if (i == 0)
			break;
		while (i >= j)
		{
			while (j != 0)
			{
				i--;
				j--;
			}
			nCoeff++;
			++j;
		}
		n--;
	}
	printf("%d\n", nCoeff);
	return (0);
}
