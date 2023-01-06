#include <stdio.h>
#include <stdlib.h>

int Hansoo(int n)
{
	int* nList = (int*)calloc(n + 1, sizeof(int));
	int dList[4] = { 0 };
	int difList[3] = { 0 };
	int i = 0, nCycle = 0, boolean = 0, nCount = 0, chkHansoo = 0;
	
	//n������ ���� �Ѽ�Ȯ�� 1���� ����
	for (i = 1; i <= n; ++i)
	{
		//�� �ڸ� ������ ��� �Ѽ� ���
		if (i < 100)
			nList[i] = i;
		//�� �ڸ� ���� �Ѽ�Ȯ��
		else
		{
			chkHansoo = i;
			nCycle = 0;
			while (chkHansoo != 0)
			{
				dList[nCycle] = chkHansoo % 10;
				chkHansoo /= 10;
				if (nCycle > 0)
					difList[nCycle - 1] = dList[nCycle] - dList[nCycle - 1];
				++nCycle;

			}

			for (int j = 0; j < nCycle - 2; ++j)
			{
				if (difList[j] == difList[j + 1])
					boolean = 1;
				else
				{
					boolean = 0;
					break;
				}
			}

			if (boolean == 1)
				nList[i] = i;
		}
	}

	for (i = 0; i <= n; ++i)
	{
		if (nList[i] != 0)
		{
			nCount++;
		}
	}

	return nCount;
}


int main(void)
{
	int N = 0;
	scanf_s("%d", &N);

	printf("%d\n", Hansoo(N));

	return 0;
}