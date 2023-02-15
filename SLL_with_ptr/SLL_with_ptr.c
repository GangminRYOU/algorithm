#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE
{
	char pszData[60];
	struct NODE* next;
}NODE;

NODE* g_pHead = NULL;
NODE* g_pTail = NULL;

int InsertAtHead(const char* pszData)
{
	NODE* pNode = (NODE*)malloc(sizeof(NODE));
	if (pNode == NULL)
		return (0);
	memset(pNode, 0, sizeof(pNode));
	strcpy_s(pNode->pszData, sizeof(pNode->pszData), pszData);
	
	if (g_pHead == NULL)
	{
		g_pHead = pNode;
		g_pTail = pNode;
	}
	else
	{
		pNode->next = g_pHead;
		g_pHead = pNode;
	}


	return (0);
}

int InsertAtTail(const char* pszData)
{
	NODE* pNode = (NODE*)malloc(sizeof(NODE));
	if (pNode == NULL)
		return (0);
	memset(pNode, 0, sizeof(NODE));
	strcpy_s(pNode->pszData, sizeof(pNode->pszData), pszData);

	if (g_pTail == NULL)
	{
		g_pHead = pNode;
		g_pTail = pNode;
	}
	else
	{
		g_pTail->next = pNode;
		g_pTail = pNode;
	}

	return (1);
}

void PrintList(void)
{
	NODE* pCurrent = g_pHead;
	while (pCurrent != NULL)
	{
		printf("[%p] %s next: [%p]\n", pCurrent, pCurrent->pszData, pCurrent->next);
		pCurrent = pCurrent->next;
	}
}

NODE* FindNode(const char* pszData)
{
	NODE* pCurrent = g_pHead;
	while (pCurrent != NULL)
	{
		if (strcmp(pCurrent->pszData, pszData) == 0)
		{
			return (pCurrent);
		}
		pCurrent = pCurrent->next;
	}
	return (NULL);
}

//만약 Dummy Node가 없고 포인터만으로 첫번째 Node를 가리키면
//FindNode에서 prev Node를 반환할 수 없다. -> 첫 번째 Node가 찾은 Node인지,
//아니면, 두 번째 Node가 찾은 Node인지 확정할 수 없기 때문에
//두 경우 모두 g_pHead가 prev Node로 반환된다.
int DeleteNode(const char* pszData)
{
	NODE* pDelete = FindNode(pszData);
	//만약 FindNode에서 pDelete를 찾지 못하거나, 리스트 자체가 없을 떄
	//지우려고 하면 에러처리 해야한다.
	if (pDelete == NULL)
		return (0);
	if (pDelete == g_pHead)
	{
		g_pHead = pDelete->next;
		printf("Deleting %s....\n", pDelete->pszData);
		free(pDelete);
		return (1);
	}
	NODE* pPrev = g_pHead;
	while (pPrev->next != pDelete)
		pPrev = pPrev->next;
	pPrev->next = pDelete->next;
	printf("Deleting %s....\n", pDelete->pszData);
	free(pDelete);
	return (1);
}

int ReleaseList(void)
{
	NODE* pCurrent = g_pHead;
	if (pCurrent == NULL)
	{
		puts("No Data to release\n");
		return (0);
	}
	NODE* pDelete;
	while (pCurrent != NULL)
	{
		pDelete = pCurrent;
		pCurrent = pCurrent->next;
		printf("Releasing %s...\n", pDelete->pszData);
		free(pDelete);
	}
	g_pHead = NULL;
	g_pTail = NULL;
	return (1);
}


int main(void)
{
	InsertAtHead("TEST01");
	InsertAtHead("TEST03");
	InsertAtTail("TEST02");
	PrintList();
	DeleteNode("TEST03");
	PrintList();
	ReleaseList();

	return (0);
}
