#include <stdio.h>

int main(void)
{
	int A, B, V;
	int n = 0;
	scanf_s("%d %d %d", &A, &B, &V);
	
	n = (V - A) / (A - B) + 1;
	if ((V - A) % (A - B) != 0)
		++n;
	printf("%d\n", n);
	return 0;
}
