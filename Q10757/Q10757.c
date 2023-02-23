#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void new_atoi(char** pLongBuf, char** pShortBuf)
{
	while (!(**pLongBuf >= '0' && **pLongBuf <= '9') || **pLongBuf == '0')
		(*pLongBuf)++;
	while (!(**pShortBuf >= '0' && **pShortBuf <= '9') || **pShortBuf == '0')
		(*pShortBuf)++;
}

void PrintReverse(char* resBuf)
{
	int i = strlen(resBuf);
	while (i >= 0)
	{
		putchar(resBuf[i]);
		i--;
	}
}


int main(void)
{
	char*	LongBuf = (char*)malloc(sizeof(char) * 10001);
	char*	ShortBuf = (char*)malloc(sizeof(char) * 10001);
	char*	resBuf = (char*)malloc(sizeof(char) * 10002);
	char*	pTmp = NULL;
	int		Round = 0, i = 0, j = 0, k = 0, nLong = 0, nShort = 0;

	scanf_s("%s", LongBuf, _msize(LongBuf));
	scanf_s("%s", ShortBuf, _msize(ShortBuf));
	memset(resBuf, 0, _msize(resBuf));

	new_atoi(&LongBuf, &ShortBuf);
	if (strlen(LongBuf) < strlen(ShortBuf))
	{
		pTmp = LongBuf;
		LongBuf = ShortBuf;
		ShortBuf = pTmp;
	}
	i = strlen(LongBuf);
	j = strlen(ShortBuf);
	i--;
	j--;
	while (i >= 0 && j >= 0)
	{
		nLong = LongBuf[i] - '0';
		nShort = ShortBuf[j] - '0';
		if (nLong + nShort + Round > 9)
		{
			resBuf[k] = (nLong + nShort + Round - 10) + '0';
			Round = 1;
		}
		else
		{
			resBuf[k] = nLong + nShort + Round + '0';
			Round = 0;
		}
		i--;
		j--;
		k++;
	}
	if (i == j && Round == 1)
		resBuf[k] = '1';
	while (i >= 0)
	{
		nLong = LongBuf[i] - '0';
		if (nLong + Round > 9)
		{
			resBuf[k] = (nLong + Round - 10) + '0';
			Round = 1;
		}
		else
		{
			resBuf[k] = nLong + Round + '0';
			Round = 0;
		}
		i--;
		k++;
	}
	PrintReverse(resBuf);

	return (0);
}
