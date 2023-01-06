#include <stdio.h>

int main(void)
{
	int A = 0, B = 0;
	scanf_s("%d%d", &A, &B);

	if (A > B)
		putchar('>');
	else if (A < B)
		putchar('<');
	else
		puts("==");
	return 0;
}