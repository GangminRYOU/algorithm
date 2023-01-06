#include <stdio.h>

int main(void) 
{
	int N = 0, TenN = 0, Ncopy = 0;
	int UnitN = 0, nCycle = 0;
	int nSum = 0, nNew = 0;
	scanf_s("%d", &N);
	if (N < 0)
		N = 0;
	else if (N > 99)
		N = 99;
	Ncopy = N;

	while (N != nNew)
	{
		TenN = Ncopy / 10;
		UnitN = Ncopy % 10;
		nSum = (TenN + UnitN) % 10;
		nNew = (UnitN * 10) + nSum;
		Ncopy = nNew;
		++nCycle;
	} 
	
	printf("%d\n", nCycle);

	return 0;
}