#include <stdio.h>


void revPrint(char* szBuffer)
{
	if(*szBuffer == '\0')
		return;
	revPrint(szBuffer + 1);
	putchar(*szBuffer);
}


int main(void)
{
	char	aBuffer[20000] = { 0 };
	char	bBuffer[20000] = { 0 };
	char	resultArr[20000] = { 0 };
	char*	aBufOp = aBuffer;
	char*	bBufOp = bBuffer;
	int		RoundUp = 0, i = 0, aLength = 0, bLength = 0;
	int aValue = 0, bValue = 0;
	scanf_s("%s", aBuffer, sizeof(aBuffer));
	scanf_s("%s", bBuffer, sizeof(bBuffer));
	//Move pointer to the end of char array
	while (*aBufOp != '\0')
		aBufOp++;
	aLength = aBufOp - aBuffer;
	aBufOp--;
	while (*bBufOp != '\0')
		bBufOp++;
	bLength = bBufOp - bBuffer;
	bBufOp--;
	//calculate from the end until if one pointer meet the front
	while (aBufOp >= aBuffer && bBufOp >= bBuffer)
	{
		aValue = *aBufOp - '0';
		bValue = *bBufOp - '0';
		if (aValue + bValue + RoundUp > 9)
		{
			resultArr[i] = (aValue + bValue + RoundUp - 10) + '0';
			RoundUp = 1;
		}
		else
		{
			resultArr[i] = aValue + bValue + RoundUp + '0';
			RoundUp = 0;
		}
		--aBufOp;
		--bBufOp;
		++i;
	}
	//if read all digits
	if (aLength == bLength)
	{
		if (RoundUp == 1)
			resultArr[i] = '1';
	}
	//if digits left in aBuffer
	else if (aLength > bLength)
	{
		while (aBufOp >= aBuffer)
		{
			aValue = *aBufOp - '0';
			if (aValue + RoundUp > 9)
			{
				resultArr[i] = (aValue + RoundUp - 10) + '0';
				RoundUp = 1;
			}
			else
			{
				resultArr[i] = aValue + RoundUp + '0';
				RoundUp = 0;
			}
			aBufOp--;
			i++;
		}
	}
	//if digits left in bBuffer
	else
	{
		while (bBufOp >= bBuffer)
		{
			bValue = *bBufOp - '0';
			if (bValue + RoundUp > 9)
			{
				resultArr[i] = (bValue + RoundUp - 10) + '0';
				RoundUp = 1;
			}
			else
			{
				resultArr[i] = bValue + RoundUp + '0';
				RoundUp = 0;
			}
			bBufOp--;
			i++;
		}

	}
	revPrint(resultArr);
	return (0);
}
