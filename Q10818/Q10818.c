#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i=0, N = 0, nMax = 0, nMin = 0;
	
	scanf_s("%d", &N);

	int* pList = (int*)calloc(N, sizeof(int));
	for (i = 0; i < N; ++i)
		scanf_s("%d", pList + i);

	nMax = pList[0];
	for (i = 1; i < N; ++i)
	{
		if (nMax < pList[i])	nMax = pList[i];
	}

	nMin = pList[0];
	for (i = 1; i < N; ++i)
		if (nMin > pList[i])
			nMin = pList[i];

	printf("%d %d\n", nMin, nMax);

	return 0;

}