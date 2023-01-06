#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N = 0, i = 0, j = 0, nScore = 0, nSum = 0;
	char szBuffer[81] = { 0 };

	scanf_s("%d%*c", &N);

	for (i = 0; i < N; ++i)
	{
		gets_s(szBuffer, sizeof(szBuffer));
		while (szBuffer[j] != 0)
		{
			if (szBuffer[j] == 'O')
			{
				++nScore;
				nSum += nScore;
			}
			else
				nScore = 0;

			szBuffer[j] = 0;
				++j;
		}
		printf("%d\n", nSum);
		nScore = 0;
		nSum = 0;
		j = 0;
	}


	return 0;
}