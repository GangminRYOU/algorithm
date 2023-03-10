#include <stdlib.h>
#include <stdio.h>

#define MAX_TERMS 101

typedef struct poly2 {
	int coef;
	int expon;
}poly2;

poly2 polyArray[MAX_TERMS] = { {10, 8}, {5, 7}, {8, 2}, {1, 1}, {9, 0} };
int avail = 5;

int exponCmp(int As, int Bs)
{
	return (polyArray[As].expon - polyArray[Bs].expon);
}

void polyAttach(int coef, int expon)
{
	polyArray[avail].coef = coef;
	polyArray[avail].expon = expon;
	avail++;
}

int polyAdd(int As, int Ae, int Bs, int Be)
{
	int Cs;
	int tempCoef;
	
	Cs = avail;
	//차수 비교후 대입, 차수가 다를 경우 두 식중 한 항만 증가해야함
	while (As <= Ae && Bs <= Be)
	{
		if (exponCmp(As, Bs) > 0)
		{
			polyAttach(polyArray[As].coef, polyArray[As].expon);
			As++;
		}
		else if (exponCmp(As, Bs) == 0)
		{
			tempCoef = polyArray[As].coef + polyArray[Bs].coef;
			if(tempCoef)
				polyAttach(tempCoef, polyArray[As].expon);
			As++;
			Bs++;
		}
		else
		{
			polyAttach(polyArray[Bs].coef, polyArray[Bs].expon);
			Bs++;
		}
	}
	//비교후 대입되지 못한 남은 항 대입
	for (; As <= Ae; As++)
		polyAttach(polyArray[As].coef, polyArray[As].expon);
	for(; Bs <= Be; Bs++)
		polyAttach(polyArray[Bs].coef, polyArray[Bs].expon);
	return (Cs);
}

int polySubstract(int As, int Ae, int Bs, int Be)
{
	int Cs;
	int tempCoef;

	Cs = avail;
	//차수 비교후 대입, 차수가 다를 경우 두 식중 한 항만 증가해야함
	while (As <= Ae && Bs <= Be)
	{
		if (exponCmp(As, Bs) > 0)
		{
			polyAttach(polyArray[As].coef, polyArray[As].expon);
			As++;
		}
		else if (exponCmp(As, Bs) == 0)
		{
			tempCoef = polyArray[As].coef - polyArray[Bs].coef;
			if (tempCoef)
				polyAttach(tempCoef, polyArray[As].expon);
			As++;
			Bs++;
		}
		else
		{
			polyAttach(-(polyArray[Bs].coef), polyArray[Bs].expon);
			Bs++;
		}
	}
	//비교후 대입되지 못한 남은 항 대입
	for (; As <= Ae; As++)
		polyAttach(polyArray[As].coef, polyArray[As].expon);
	for (; Bs <= Be; Bs++)
		polyAttach(-(polyArray[Bs].coef), polyArray[Bs].expon);
	return (Cs);
}

int findExpon(int x, int s, int e)
{
	for (int i = s; i <= e; ++i)
	{
		if (polyArray[i].expon == x)
			return (polyArray[i].coef);
	}
	return (0);
}

poly2 polyEval(int x, int As, int Ae, int Bs, int Be)
{
	int Acoef;
	int Bcoef;
	poly2 resInstance;
	
	Acoef = findExpon(x, As, Ae);
	Bcoef = findExpon(x, Bs, Be);
	resInstance.coef = Acoef + Bcoef;
	resInstance.expon = x;
	return (resInstance);
}

void printPoly(int s, int e)
{
	while (s < e)
	{
		printf("%dx^%d + ", polyArray[s].coef, polyArray[s].expon);
		s++;
	}
	if (polyArray[s].expon == 0)
		printf("%d\n", polyArray[s].coef);
	else
		printf("%dx^%d\n", polyArray[s].coef, polyArray[s].expon);
}

int main(void)
{
	int Cs;
	int Ce;
	int Ds;
	int De;
	int Ee;
	int Es;
	poly2 result;

	printPoly(0, 1);
	printPoly(2, 4);
	Cs = polyAdd(0, 1, 2, 4);
	Ce = avail - 1;
	printPoly(Cs, Ce);
	Ds = polySubstract(Cs, Ce, 2, 4);
	De = avail - 1;
	printPoly(Ds, De);
	Es = polySubstract(Ds, De, 2, 4);
	Ee = avail - 1;
	printPoly(Es, Ee);
	result = polyEval(2, Ds, De, Es, Ee);
	printf("%dx^%d\n", result.coef, result.expon);
	return (0);
}
