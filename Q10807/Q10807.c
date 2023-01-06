#include <stdio.h>
int main(void)
{
	int N = 0, v = 0, i = 0, vNumber = 0; 
	scanf_s("%d", &N);
	
	int nArray[100] = { 0 };
	for (i = 0; i < N; ++i)
	{
		scanf_s("%d", &nArray[i]);
	}
	
	scanf_s("%d", &v);

	for (i = 0; i < N; ++i)
	{
		if (nArray[i] == v)
			++vNumber;
	}

	printf("%d\n", vNumber);

	return 0;
}