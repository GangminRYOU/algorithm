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
		//�Է� ���� ���ڿ��� ���� �˻�
		pszBuffer = szBuffer;
		while (*pszBuffer != '\0')
			++pszBuffer;
		sLength = pszBuffer - szBuffer;
		//���ο� ���ڿ� P�� ���� �����Ҵ� ������
		pszBuffer = (char*)calloc(R * sLength + 1, sizeof(char));
		//�Է¹��� ���ڿ��� ���̸�ŭ �ݺ�
		for (k = 0; k < sLength; ++k)
		{
			//R��ŭ �� ��� �ݺ�
			for (j = 0; j < R; ++j)
			{
				pszBuffer[j] = szBuffer[k];
			}
			//R��ŭ ���� ��, ���� ���ڿ� ������ ���� ������ �̵�
			pszBuffer += j;
		}
		//����� ���� ���ڿ��� �������� ������ �̵�
		pszBuffer -= sLength * R;
		puts(pszBuffer);
	}

	free(pszBuffer);

	return 0;
}