#include <stdio.h>

int main(void)
{
	int i = 0, nMax = 0, nIndex = 0;
	int aList[9] = { 0 };
	

	for (i = 0; i < 9; ++i)
		scanf_s("%d", &aList[i]);
	

	for (i = 0; i < 9; ++i)
		if (nMax < aList[i])
		{
			nMax = aList[i];
			nIndex = i+1;
		}
	
	printf("%d\n%d\n", nMax, nIndex);

	return 0;
}