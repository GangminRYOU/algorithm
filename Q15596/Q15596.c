#include <stdio.h>
#include <stdlib.h>

long long int Sum(int* a, int n)
{
	int i = 0;
	long long int nSum = 0LL;
	for (i = 0; i < n; ++i)
		nSum += a[i];

		

	return nSum;
}

int main(void)
{
	int N = 0, i = 0;
	//�迭�� ����
	scanf_s("%d", &N);
	int* aList = (int*)calloc(N, sizeof(N));
	//�迭 ����� �� �Է�
	for (i = 0; i < N; ++i)
		scanf_s("%d", aList + i);

	printf("%lld\n", Sum(aList, N));
	return 0;
}