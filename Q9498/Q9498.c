#include <stdio.h>

int main(void)
{
	int nScore = 0;
	scanf_s("%d", &nScore);

	if (nScore >= 70)
	{
		if (nScore >= 90)
			putchar('A');
		else
		{
			if (nScore >= 80)
				putchar('B');
			else
				putchar('C');
		}
		
	}
	else
	{
		
		if (nScore >= 60)
			putchar('D');
		else
			putchar('F');
	}
	return 0;
}