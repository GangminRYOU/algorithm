#include <stdio.h>

int main(void)
{
	int nYear = 0;
	scanf_s("%d", &nYear);

	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
		printf("%d\n", 1);
	else
		printf("%d\n", 0);

	return 0;
	

}