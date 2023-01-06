#include <stdio.h>

int main(void)
{
	int nTotal = 0, N = 0, nSum = 0, nPrice =0, nCount =0;
	scanf_s("%d\n%d", &nTotal, &N);
	
	
	
	while (N != 0)
	{
		scanf_s("%d%d", &nPrice, &nCount);
		nSum += (nPrice * nCount);
		printf("%d\n", nSum);
		--N;
	}

	if (nTotal == nSum)
		puts("Yes");
	else
		puts("No");
	return 0;


}