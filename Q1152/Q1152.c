#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char szBuffer[1000000] = { 0 };
	int wCount = 0;
	char* pszBuffer = szBuffer;
	
	gets_s(szBuffer, sizeof(szBuffer));

	while (*pszBuffer != '\0')
	{
		if (*pszBuffer == ' ')
			++wCount;
		++pszBuffer;
	}
	if (szBuffer[0] == ' ')
		--wCount;
	if (*(pszBuffer - 1) == ' ')
		--wCount;
	printf("%d\n", wCount+1);

	return 0;
}