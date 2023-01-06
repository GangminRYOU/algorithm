#include <stdio.h>

int main(void)
{
	int A = 0, B = 0, T = 0;

	scanf_s("%d", &T);

	for(int i =1;i<T+1;++i)
	{
		scanf_s("%d%d", &A, &B);
		printf("Case #%d: %d + %d = %d\n", i,A, B, A + B);

	}

	return 0;
}