#include <stdio.h>

void main(void)
{
	int A = 0, B = 0, C = 0;
	scanf_s("%d%d\n%d", &A, &B, &C);

	B += C;
	if (B / 60 >= 1)
	{
		A += B / 60;
		B %= 60;
	}

	if (A > 23)
	{
		A -= 24;
	}

	printf("%d %d", A, B);


}