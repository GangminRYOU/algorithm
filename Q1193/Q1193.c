#include <stdio.h>

int main(void)
{
	int X = 0;
	int nColumn = 0;
	int nextColumn = 1;
	int nRow = 0;
	int n = 0;
	int nflag = 0;
	int RowNum = 0;
	int ColNum = 0;
	int kNum = 0;
	int d = 0;
	scanf_s("%d", &X);
	if (X == 1)
	{
		puts("1/1\n");
		return 0;
	}
	while (1)
	{
		nColumn += 1 + 4 * n;
		nextColumn += 1 + 4 * (n + 1);
		nRow += 3 + 4 * n;
		if (nColumn < X && X <= nRow)
		{
			nflag = 1;
			break;
		}
		if (nRow < X && X <= nextColumn)
		{
			nflag = 2;
			break;
		}
		++n;
	}
	if (nflag == 1)
	{
		RowNum = 1 + 2 * n;
		while (nRow != X)
		{
			nRow--;
			++d;
		}
		RowNum -= d;
		ColNum += d;
		printf("%d/%d\n", RowNum + 1, ColNum + 1);
	}
	if (nflag == 2)
	{
		ColNum = 2 * (n + 1);
		while (nextColumn != X)
		{
			nextColumn--;
			++d;
		}
		ColNum -= d;
		RowNum += d;
		printf("%d/%d\n", RowNum + 1, ColNum + 1);
	}


	return (0);
}
