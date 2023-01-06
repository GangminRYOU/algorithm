#include <stdio.h>

int main(void)
{
	int n = 0;
	int nSum = 0;
	scanf_s("%d", &n);

	while (n != 0)
	{
		nSum += n--;
	}

	printf("%d\n", nSum);

	return 0;
}