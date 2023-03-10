#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DEGREE 101

typedef struct s_poly {
	int degree;
	int coef[MAX_DEGREE];
}poly;

poly addPoly(poly a, poly b)
{
	int lDegree;
	int sDegree;
	if (a.degree > b.degree)
	{
		lDegree = a.degree;
		sDegree = b.degree;
		while (sDegree >= 0)
		{
			a.coef[lDegree] += b.coef[sDegree];
			--lDegree;
			--sDegree;
		}
		return (a);
	}
	else
	{
		lDegree = b.degree;
		sDegree = a.degree;
		while (sDegree >= 0)
		{
			b.coef[lDegree] += a.coef[sDegree];
			--lDegree;
			--sDegree;
		}
		return (b);
	}
}

void printPoly(poly result)
{
	printf("degree: %d\n", result.degree);
	printf("Poly: ");
	for(int i = 0; i <= result.degree; ++i)
		printf("%d ", result.coef[i]);
}

int main(void)
{
	poly a = { 5, {10, 0, 0, 0, 6, 3} };
	poly b = { 3, {10, 2, 4, 4} };
	poly result;
	result = addPoly(a, b);
	printPoly(result);
	return (0);
}
