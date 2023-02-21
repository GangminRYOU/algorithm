#include <stdio.h>

void PrintTable(int(*arr)[14])
{
	for (int i = 14; i >= 0; --i)
	{
		for (int j = 0; j < 14; ++j)
			printf("%d ", arr[i][j]);
		putchar('\n');
	}
}



int main(void)
{
	int T = 0, k = 0, n = 0, i = 0, j = 0;
	int d = 0, count = 0, kmax = 0, nmax = 0;
	int arr[15][14] = {0};

	//Initialize
	for (i = 0; i < 15; i++)
		arr[i][0] = 1;
	for (j = 0; j < 14; ++j)
		arr[0][j] = ++d;
	//fisrt input
	scanf_s("%d", &T);
	scanf_s("%d%d", &k, &n);
	for (i = 1; i <= k; ++i)
		for (j = 1; j <= n - 1; ++j)
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
	printf("%d\n", arr[k][n - 1]);
	kmax = k;
	nmax = n - 1;
	//subsequential inputs
	for (count = 1; count < T; ++count)
	{
		scanf_s("%d%d", &k, &n);
		
		//already know value
		if (k <= kmax && n - 1 <= nmax)
			printf("%d\n", arr[k][n - 1]);
		//need to fill row
		else if (k <= kmax && n - 1 > nmax)
		{
			for(i = 1; i <= k; ++i)
				for(j = nmax + 1; j <= n - 1; ++j)
					arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			printf("%d\n", arr[k][n - 1]);
		}
		//need to fill column
		else if (k > kmax && n - 1 <= nmax)
		{
			for (i = kmax + 1; i <= k; ++i)
				for (j = 1; j <= n - 1; ++j)
					arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			printf("%d\n", arr[k][n - 1]);
		}
		//need to fill row and column which are not filled
		else
		{
			for(i = 1; i <= kmax; ++i)
				for(j = nmax + 1; j <= n - 1; ++j)
					arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			for (i = kmax + 1; i <= k; ++i)
				for(j = 1; j <= n - 1; ++j)
					arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			printf("%d\n", arr[k][n - 1]);
		}
		//init max value
		if (k > kmax)
			kmax = k;
		if (n > nmax)
			nmax = n - 1;
	}
	return (0);
}
