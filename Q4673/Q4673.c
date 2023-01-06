#include <stdio.h>
#include <stdlib.h>

void SelfNoList(int* nList)
{
	int n = 0, i = 0, sum =0;
	for (i = 1; i <= 10000; ++i)
	{
			n = i;
			sum = n;
			while (n != 0)
			{
				sum += n % 10;
				n /= 10;	
			}
			if(sum <= 10000)
				nList[sum] = sum;
	}
}

int main(void)
{
	int* nList = (int*)calloc(10001, sizeof(int));
	int i = 0;
	
	SelfNoList(nList);
	for (i = 1; i <= 10000; ++i)
	{
		if(nList[i] == 0)
			printf("%d\n", i);
	}
	
	free(nList);

	return 0;
}