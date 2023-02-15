#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE
{
	char szData[60];
	struct NODE* next;
}NODE;

NODE* g_pHead = NULL;
NODE* g_pTail = NULL;

int InitList(void)
{
	g_pHead = (NODE*)malloc(sizeof(NODE));
	if (g_pHead == NULL)
		return (0);
	memset(g_pHead, 0, sizeof(NODE));
	g_pTail = (NODE*)malloc(sizeof(NODE));
	if (g_pTail == NULL)
		return (0);
	memset(g_pTail, 0, sizeof(NODE));

	g_pHead->next = g_pTail;
	return (1);
}

int InsertBefore(NODE* pDstNode, const char* pszData)
{
	NODE* pPrev = g_pHead;
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	if (newNode == NULL)
		return (0);
	memset(newNode, 0, sizeof(NODE));
	strcpy_s(newNode->szData, sizeof(newNode->szData), pszData);

	//Double Linked List가 아니기 떄문에 넣을 위치의
	//앞쪽 Node를 찾는다.
	while (pPrev->next != pDstNode)
		pPrev = pPrev->next;
	newNode->next = pDstNode;
	pPrev->next = newNode;

	return (1);
}

int InsertAfter(NODE* pDstNode, const char* pszData)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	if (newNode == NULL)
		return (0);
	memset(newNode, 0, sizeof(NODE));
	strcpy_s(newNode->szData, sizeof(newNode->szData), pszData);
	
	newNode->next = pDstNode->next;
	pDstNode->next = newNode;
	
	return (1);
}



int InsertAtHead(const char* pszData)
{
	if(InsertAfter(g_pHead, pszData))
		return (1);
	return (0);

}


int InsertAtTail(const char* pszData)
{
	if (InsertBefore(g_pTail, pszData))
		return (1);
	return (0);
}


//기존의 FindNode는 전 Node를 찾았으나, 그 방식은 InsertAtHead와 Tail이 g_pHead의 전 노드를 매개변수로 넣거나
// g_pTail의 뒷 노드를 매개변수로 넣어야 동작하는 식으로
//꼬이기 떄문에 현재 Node를 찾는 방식으로 바꿈
NODE* FindNode(const char* pszData)
{
	//InsertBefore, After에서 만약 pszData가 0인 노드를
	//찾는다면 Dummy Node와 Tail의 앞과 뒤에 붙여 넣을 수 있기 때문에
	//예외처리
	if (pszData == 0)
		return (NULL);
	NODE* pCurrent = g_pHead->next;
	while (pCurrent != NULL)
	{
		if (strcmp(pCurrent->szData, pszData) == 0)
			return (pCurrent);
		pCurrent = pCurrent->next;
	}
	//찾지 못한 경우
	return (NULL);
}


//이러면 DeleteNode에서 pPrev를 찾기위한 반복, InsertBefore에서 pPrev를 찾기위한 반복연산
//차라리 index로 찾을까 생각도 했지만 어짜피 거기서도 인덱싱을 위한 반복연산이 생김
//그냥 이 방법이 나은거 같다. (하지만 사용 빈도를 봤을때 어떤 함수를 더 많이 사용할까?)
void DeleteNode(const char* pszData)
{
	NODE* pDelete = FindNode(pszData);
	NODE* pPrev = g_pHead;
	while (pPrev->next != pDelete)
		pPrev = pPrev->next;
	pPrev->next = pDelete->next;
	printf("Deleting %s...\n", pDelete->szData);
	free(pDelete);
}

void PrintList(void)
{
	NODE* pCurrent = g_pHead->next;
	puts("PrintList Called\n");
	while (pCurrent != g_pTail)
	{
		printf("[%p] %s  next: [%p]\n", pCurrent, pCurrent->szData, pCurrent->next);
		pCurrent = pCurrent->next;
	}
}

void ReleaseList(void)
{
	NODE* pCurrent = g_pHead;
	while (pCurrent != NULL)
	{
		printf("Releasing %s..\n", pCurrent->szData);
		pCurrent = pCurrent->next;
	}

	g_pHead = NULL;
	g_pTail = NULL;
	puts("List Successfully Released\n");
}

int main(void)
{
	InitList();
	InsertAtHead("TEST01");
	InsertAtHead("TEST02");
	InsertAtHead("TEST03");
	InsertAtHead("TEST04");
	InsertAtHead("TEST05");
	InsertAtTail("TEST00");
	InsertAtTail("TEST-01");
	InsertAtTail("TEST-02");
	InsertAtTail("TEST-03");
	PrintList();
	InsertAfter(FindNode("TEST04"), "TEST07");
	InsertAfter(FindNode("TEST-03"), "TEST-04");
	InsertBefore(FindNode("TEST05"), "TEST06");
	InsertBefore(FindNode("TEST00"), "TEST09");
	PrintList();
	DeleteNode("TEST05");
	DeleteNode("TEST03");
	DeleteNode("TEST-02");
	DeleteNode("TEST-01");
	PrintList();

	ReleaseList();

	return (0);
}
