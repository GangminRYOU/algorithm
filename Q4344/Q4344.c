#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int TC = 0, EC = 0, i=0, j=0, nStudents = 0;
	float nAverage = 0.0, fRate = 0.0;
	int* nList = NULL;


	scanf_s("%d", &TC);
	//TC만큼 반복 시작
	for (i = 0; i < TC; ++i)
	{
		scanf_s("%d", &EC);
		//EC 크기 측정 및 동적할당
		if (EC > 1000 || EC < 1)
			return;
		nList = (int*)calloc(EC, sizeof(int));
		//nSum, nStudents EC값을 받을 떄마다 초기화
		int nSum = 0;
		nStudents = 0;
		// 각 학생의 점수를 받고, 합을 구한다.
		for (j = 0; j < EC; ++j)
		{
			scanf_s("%d", nList + j);
			nSum += nList[j];
		}
		//평균 계산
		nAverage = (float)nSum / EC;
		printf("%f\n", nAverage);
		//평균를 넘는 학생의 수 계산
		for(j=0 ; j<EC; ++j)
			if (nList[j] > nAverage)
				nStudents++;
		//비율 계산과 소수점 넷째 자리 반올림
		fRate = ((float)nStudents / EC)*100.0;
		/*printf("%2.3f\n", fRate);
		if ((fRate * 10000.0) - ((int)(fRate * 10000.0) / 10)*10 >= 5)
			fRate += 0.001;*/

		printf("%0.3f%%\n", fRate);
	}
	
	return 0;
}