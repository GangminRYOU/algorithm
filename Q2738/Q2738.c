#include <stdio.h>
#include <stdlib.h>

void Make_Table(int N, int M, int*** Atable, int*** Btable)
{
	*Atable = (int**)calloc(N, sizeof(int*));
	for (int i = 0; i < N; ++i)
		(*Atable)[i] = (int*)calloc(M, sizeof(int));
	*Btable = (int**)calloc(N, sizeof(int*));
	for (int i = 0; i < N; ++i)
		(*Btable)[i] = (int*)calloc(M, sizeof(int));
}

int** Add_Table(int N, int M, int** Atable, int** Btable)
{
	int** resTable = (int **)calloc(N, sizeof(int*));
	for (int i = 0; i < N; ++i)
		resTable[i] = (int*)calloc(M, sizeof(int));
	for(int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			resTable[i][j] = Atable[i][j] + Btable[i][j];
	return (resTable);
}


int main(void)
{
	int		N = 0, M = 0;
	int**	Atable = NULL;
	int**	Btable = NULL;
	int**	resTable = NULL;

	scanf_s("%d%d", &N, &M);
	Make_Table(N, M, &Atable, &Btable);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf_s("%d", &Atable[i][j]);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf_s("%d", &Btable[i][j]);
	resTable = Add_Table(N, M, Atable, Btable);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			printf("%d ", resTable[i][j]);
		putchar('\n');
	}


	return(0);
}
