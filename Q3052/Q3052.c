#include <stdio.h>

int main(void)
{
	int i = 0, j =0, n=0;
	int aList[10] = { 0 };
	int nList[10] = { 0 };
	for (i = 0; i < 10; ++i)
	{
		scanf_s("%d", &aList[i]);
		aList[i] %= 42;
	}
	for (i = 0; i < 9; ++i)
	{
		for (j = i + 1; j < 10; ++j)
		{
			if (aList[i] == aList[j])
			{
				nList[i] = 43;
				break;
			}
		}
		if (nList[i] != 43)
			++n;
	}

	

	printf("%d\n", n+1);


	return 0;
}