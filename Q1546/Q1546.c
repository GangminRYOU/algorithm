#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int N = 0, i = 0, nInput = 0;
	double dSum = 0, dMax = -9999;
	scanf_s("%d", &N);
	double* pList = (double*)calloc(N, sizeof(double));

	for (i = 0; i < N; ++i)
	{
		scanf_s("%d", &nInput);
		pList[i] = (double)nInput;
	}
	
	for (i = 0; i < N; ++i)
	{
		if (dMax < pList[i])
			dMax = pList[i];
	}

	for (i = 0; i < N; ++i)
	{
		pList[i] = (pList[i] / dMax) * 100;
		dSum += pList[i];
	}
	
	printf("%f\n", dSum / N);

	free(pList);

	return 0;
}