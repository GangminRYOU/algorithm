#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char szBuffer[100] = { 0 };
	int nCount = 0;
	char* pCH = szBuffer;

	gets_s(szBuffer, sizeof(szBuffer));

	while (*pCH != '\0')
	{
		if (*pCH == 'd' && *(pCH + 1) == 'z' && *(pCH + 2) == '=')
			pCH += 2;
		else if (*(pCH + 1) == '=' || *(pCH + 1) == '-')
			++pCH;
		else if (*pCH == 'n' && *(pCH + 1) == 'j')
			++pCH;
		else if (*pCH == 'l' && *(pCH + 1) == 'j')
			++pCH;

		++nCount;
		++pCH;
	}

	printf("%d\n", nCount);

	return 0;
}