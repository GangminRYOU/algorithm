#include <stdio.h>

int main(void)
{
	int nA = 0, nB = 0, nC = 0;
	scanf_s("%d%d%d", &nA, &nB, &nC);

	printf("%d\n%d\n%d\n%d\n",
		(nA + nB) % nC,
		((nA % nC) + (nB % nC)) % nC,
		(nA * nB) % nC,
		((nA % nC) * (nB % nC)) % nC);

	return 0;
}