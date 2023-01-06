#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char szBuffer[101] = { 0 };
	char alphabet[26] = { "abcdefghijklmnopqrstuvwxyz" };
	int* pIndex = (int*)malloc(26*sizeof(int));
	memset(pIndex, -1, 26*sizeof(int));

	int i = 0, j = 0;
	gets_s(szBuffer, sizeof(szBuffer));

	for (i = 0; i < 26; ++i)
	{
		for (j = 0; j < 101; ++j)
		{
			if (szBuffer[j] == '\0')
				break;
			if (alphabet[i] == szBuffer[j])
			{
				pIndex[i] = j;
			
				break;
			}
		}
	}

	for (i = 0; i < 26; ++i)
	{
		printf("%d ", pIndex[i]);
	}
	
	free(pIndex);
	return 0;
}