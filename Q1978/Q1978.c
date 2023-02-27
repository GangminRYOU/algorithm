#include <stdio.h>

int is_prime(int nData)
{
	int i = 2;
	if (nData == 1)
		return (0);
	while (i <= nData / i)
	{
		if (nData % i == 0)
			return (0);
		++i;
	}
	return (1);
}




int main(void)
{
	int N = 0, cnt = 0, nData = 0;
	scanf_s("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &nData);
		if (is_prime(nData))
			cnt++;
	}
	printf("%d\n", cnt);
	return (0);
}
