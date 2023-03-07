#include <stdio.h>

int bin_co(int n, int k)
{
	if (k == 0 || k == n)
		return (1);
	return (bin_co(n - 1, k - 1) + bin_co(n - 1, k));
}

int main(void)
{
	int coeff = bin_co(2, 1);
	printf("%d\n", coeff);
}
