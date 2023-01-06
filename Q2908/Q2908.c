#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char d1Buffer[5] = { 0 };
	char d2Buffer[5] = { 0 };
	int d1Data = 0, d2Data = 0;
	scanf_s("%s ", d1Buffer, sizeof(d1Buffer));
	gets_s(d2Buffer, sizeof(d2Buffer));
	
	d1Data = 100 * (d1Buffer[2] - 48) + 10 * (d1Buffer[1] - 48) + (d1Buffer[0] - 48);
	d2Data = 100 * (d2Buffer[2] - 48) + 10 * (d2Buffer[1] - 48) + (d2Buffer[0] - 48);
	
	if (d1Data > d2Data)
		printf("%d\n", d1Data);
	else
		printf("%d\n", d2Data);

	return 0;
}