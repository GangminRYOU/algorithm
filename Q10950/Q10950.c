#include <stdio.h>

int main(void)
{
	int A = 0, B = 0, T = 0;
	scanf_s("%d", &T);

	while (T>0)
	{
		scanf_s("%d%d", &A, &B);
		printf("%d\n", A + B);
		--T;
	}

	return 0;
}