#include <stdio.h>

int main(void)
{
	int nSrc = 0, nDst = 0;
	scanf_s("%d%d", &nSrc, &nDst);

	printf("%d\n%d\n%d\n%d\n",
		nSrc * ((nDst % 10) / 1),
		nSrc * ((nDst % 100) / 10),
		nSrc * ((nDst % 1000) / 100),
		nSrc * nDst);

	return 0;
}