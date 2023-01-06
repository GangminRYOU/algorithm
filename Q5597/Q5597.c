#include <stdio.h>

int main(void)
{
	int i = 0, n =0;
	int aList[31] = { 0 };
	
	for (i = 0; i <28; ++i)
	{
		scanf_s("%d", &n);
		aList[n] = n;
	}

	for (i = 1; i < 31; ++i)
		if (aList[i] == 0)
			printf("%d\n", i);
	 

	return 0;
}