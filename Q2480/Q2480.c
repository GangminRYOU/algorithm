#include <stdio.h>

int main(void)
{
	int A = 0, B = 0, C = 0, nReward = 0;
	
	scanf_s("%d%d%d", &A, &B, &C);
	int nMax = A;

	if (A == B && B == C)
	{
		nReward = 10000 + A * 1000;
	}
	else if (A == B)
	{
		nReward = 1000 + A * 100;
	}
	else if (B == C)
	{
		nReward = 1000 + B * 100;
	}
	else if (C == A)
	{
		nReward = 1000 + C * 100;
	}
	else
	{
		if (nMax < B)
			nMax = B;
		if (nMax < C)
			nMax = C;

		nReward = nMax * 100;
	}
	printf("%d\n", nReward);
	return 0;

}