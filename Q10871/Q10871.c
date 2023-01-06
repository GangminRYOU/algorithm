#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int N = 0, X = 0, i=0;
	scanf_s("%d%d", &N, &X);

	int* aList = (int*)calloc(N, sizeof(int));

	for (i = 0; i < N; ++i)
	{
		scanf_s("%d", aList+i);
	}

	for (i = 0; i < N; ++i)
	{
		if (aList[i] < X)
			printf("%d\t", *(aList+i));
	}


	

	return 0;
}