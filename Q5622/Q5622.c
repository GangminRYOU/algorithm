#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char szBuffer[16] = { 0 };
	int nList[16] = { 0 };
	int i = 0, nSum = 0;

	gets_s(szBuffer, sizeof(szBuffer));

	while (szBuffer[i] != '\0')
	{
		if (szBuffer[i] <= 'L')
		{
			if (szBuffer[i] > 'F')
			{
				if (szBuffer[i] > 'I')
					nList[i] = 5;
				else
					nList[i] = 4;
			}
			else
			{
				if (szBuffer[i] > 'C')
					nList[i] = 3;
				else
					nList[i] = 2;
			}
		}
		else
		{
			if (szBuffer[i] > 'S')
			{
				if (szBuffer[i] > 'V')
					nList[i] = 9;
				else
					nList[i] = 8;
			}
			else
			{
				if (szBuffer[i] < 'P')
					nList[i] = 6;
				else
					nList[i] = 7;
			}
		}

		++i;
	}
	--i;
	while (i >= 0)
	{
		nSum += nList[i] + 1;
		--i;
	}

	printf("%d\n", nSum);

	return 0;
}