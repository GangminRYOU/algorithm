#include <stdio.h>

int main(void)
{
	int N = 0, X = 0, Y = 0, nMin = 0, nTotal = 0;
	scanf_s("%d", &N);
	if (N % 5 == 0)
	{
		nTotal = N / 5;
		nMin = nTotal;
	}
	if (N % 3 == 0)
	{
		nTotal = N / 3;
		if(nTotal < nMin || nMin == 0)
			nMin = nTotal;
	while (X * 3 < N)
	{
		++X;
		if ((N - X * 3) % 5 == 0)
		{
			Y = (N - X * 3) / 5;
			nTotal = X + Y;
			if (nTotal < nMin || nMin == 0)
				nMin = nTotal;
			break;
		}
	}
	X = 0;
	Y = 0;
	while (N - Y * 5 < 0)
	{
		Y = N / 5;
		if ((N - Y * 5) % 3 == 0)
		{
			X = (N - Y * 5) / 3;
			nTotal = X + Y;
			if (nTotal < nMin || nMin == 0)
				nMin = nTotal;
		}
		--Y;
	}
	if (nMin == 0)
		printf("%d\n", -1);
	else
		printf("%d\n", nMin);
	return (0);
}
