#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	int nMax = 0, i = 0, j = 0, nLength = 0;
	int mCount = 0;
	char ch = 0;
	char Alphabet[26] = { "abcdefghijklmnopqrstuvwxyz"};
	char szBuffer[1000001] = { 0 };
	char* pLength = szBuffer;
	int* nList = (int*)calloc(26, sizeof(int));

	gets_s(szBuffer, sizeof(szBuffer));
	while (*pLength != '\0')
		++pLength;
	nLength = pLength - szBuffer;
	
	//������ Ƚ�� ��
	for (i = 0; i < 26; ++i)
		for (j = 0; j < nLength; ++j)
			if (Alphabet[i] == tolower(szBuffer[j]))
				++nList[i];
	//�ִ����Ƚ�� ���ϱ�
	for (i = 0; i < 26; ++i)
	{
		if (nMax < nList[i])
		{
			nMax = nList[i];
			ch = Alphabet[i];
		}

	}
	//�ִ� ���� ���ĺ� 2�� �̻� ����
	for (i = 0; i < 26; ++i)
		if (nList[i] == nMax)
			++mCount;
	if (mCount > 1)
		putchar('?');
	else
		putchar(toupper(ch));

	return 0;
}