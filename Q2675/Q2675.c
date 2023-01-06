#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int T = 0, R = 0;
	int i = 0, j = 0, k = 0, p = 0, sLength = 0;
	char szBuffer[21] = { 0 };
	char* pszBuffer = NULL;
	scanf_s("%d", &T);

	for (i = 0; i < T; ++i)
	{
		scanf_s("%d%*c", &R);
		gets_s(szBuffer, sizeof(szBuffer));
		//입력 받은 문자열의 길이 검사
		pszBuffer = szBuffer;
		while (*pszBuffer != '\0')
			++pszBuffer;
		sLength = pszBuffer - szBuffer;
		//새로운 문자열 P를 만들 동적할당 포인터
		pszBuffer = (char*)calloc(R * sLength + 1, sizeof(char));
		//입력받은 문자열의 길이만큼 반복
		for (k = 0; k < sLength; ++k)
		{
			//R만큼 각 요소 반복
			for (j = 0; j < R; ++j)
			{
				pszBuffer[j] = szBuffer[k];
			}
			//R만큼 대입 후, 다음 문자열 대입을 위한 포인터 이동
			pszBuffer += j;
		}
		//출력을 위해 문자열의 시작으로 포인터 이동
		pszBuffer -= sLength * R;
		puts(pszBuffer);
	}

	free(pszBuffer);

	return 0;
}