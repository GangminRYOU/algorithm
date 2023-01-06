#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int TC = 0, EC = 0, i=0, j=0, nStudents = 0;
	float nAverage = 0.0, fRate = 0.0;
	int* nList = NULL;


	scanf_s("%d", &TC);
	//TC��ŭ �ݺ� ����
	for (i = 0; i < TC; ++i)
	{
		scanf_s("%d", &EC);
		//EC ũ�� ���� �� �����Ҵ�
		if (EC > 1000 || EC < 1)
			return;
		nList = (int*)calloc(EC, sizeof(int));
		//nSum, nStudents EC���� ���� ������ �ʱ�ȭ
		int nSum = 0;
		nStudents = 0;
		// �� �л��� ������ �ް�, ���� ���Ѵ�.
		for (j = 0; j < EC; ++j)
		{
			scanf_s("%d", nList + j);
			nSum += nList[j];
		}
		//��� ���
		nAverage = (float)nSum / EC;
		printf("%f\n", nAverage);
		//��ո� �Ѵ� �л��� �� ���
		for(j=0 ; j<EC; ++j)
			if (nList[j] > nAverage)
				nStudents++;
		//���� ���� �Ҽ��� ��° �ڸ� �ݿø�
		fRate = ((float)nStudents / EC)*100.0;
		/*printf("%2.3f\n", fRate);
		if ((fRate * 10000.0) - ((int)(fRate * 10000.0) / 10)*10 >= 5)
			fRate += 0.001;*/

		printf("%0.3f%%\n", fRate);
	}
	
	return 0;
}