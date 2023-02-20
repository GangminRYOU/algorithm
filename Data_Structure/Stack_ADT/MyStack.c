#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MyStack.h";

//자료구조를 만드는 사람 입장

//객체 생성 코드
int InitList(LIST_INFO* ListObject)
{
	ListObject->pHead = (NODE*)malloc(sizeof(NODE));
	if (ListObject->pHead == NULL)
		return (0);
	memset(ListObject->pHead, 0, sizeof(NODE));
	ListObject->pTail = (NODE*)malloc(sizeof(NODE));
	if (ListObject->pTail == NULL)
		return (0);
	memset(ListObject->pTail, 0, sizeof(NODE));
	ListObject->nSize = 0;
	ListObject->pHead->next = ListObject->pTail;
	return (1);
}

int InsertBefore(LIST_INFO* ListObject, NODE* pDstNode, void* pParam, const char* (*U_GetKey)(void*))
{
	NODE* pPrev = FindPrev(ListObject, pDstNode->pfGetKey(pDstNode->pData));
	if (pPrev == NULL)
		return (0);
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	if (pNewNode == NULL)
		return (0);
	memset(pNewNode, 0, sizeof(NODE));
	pNewNode->pData = pParam;
	pNewNode->pfGetKey = U_GetKey;
	
	pNewNode->next = pDstNode;
	pPrev->next = pNewNode;

	ListObject->nSize++;
	return (ListObject->nSize);
}

int InsertAfter(LIST_INFO* ListObject, NODE* pDstNode, void* pParam, const char* (*U_GetKey)(void*))
{
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	if (pNewNode == NULL)
		return (0);
	memset(pNewNode, 0, sizeof(NODE));

	pNewNode->pData = pParam;
	pNewNode->pfGetKey = U_GetKey;

	pNewNode->next = pDstNode->next;
	pDstNode->next = pNewNode;
	ListObject->nSize++;
	return (ListObject->nSize);
}

int InsertAtHead(LIST_INFO* ListObject, void* pParam, const char* (*U_GetKey)(void*))
{
	return (InsertAfter(ListObject, ListObject->pHead, pParam, U_GetKey));
}

int InsertAtTail(LIST_INFO* ListObject, void* pParam, const char* (*U_GetKey)(void*))
{
	return (InsertBefore(ListObject, ListObject->pTail, pParam, U_GetKey));
}

//Stack Structure Push function
int PushData(LIST_INFO* ListObject, void* pParam, const char* (*U_GetKey)(void*))
{
	return (InsertAtHead(ListObject, pParam, U_GetKey));
}


//Stack Structure Pop function
int PopData(LIST_INFO* ListObject, void* pParam)
{
	NODE* pDelete = ListObject->pHead->next;
	ListObject->pHead->next = ListObject->pHead->next->next;

	memcpy(pParam, pDelete->pData, _msize(pDelete->pData));
	printf("Popped %s\n", pDelete->pfGetKey(pDelete->pData));
	free(pDelete->pData);
	free(pDelete);
	ListObject->nSize--;
	return (ListObject->nSize);
}


NODE* FindPrev(LIST_INFO* ListObject, const char* pszKey)
{
	NODE* pPrev = ListObject->pHead;
	while (pPrev != ListObject->pTail)
	{
		if (strcmp(pPrev->next->pfGetKey(pPrev->next->pData), pszKey) == 0)
			return (pPrev);
		pPrev = pPrev->next;
	}
	return (NULL);
}

NODE* FindNode(LIST_INFO* ListObject, const char* pszKey)
{
	NODE* pPrev = FindPrev(ListObject, pszKey);
	if (pPrev == NULL)
		return (NULL);
	NODE* pDstNode = pPrev->next;
	if (pDstNode == NULL)
		return (NULL);
	return (pDstNode);
}

int DeleteNode(LIST_INFO* ListObject, const char* pszKey)
{
	NODE* pPrev = FindPrev(ListObject, pszKey);
	NODE* pDelete = pPrev->next;

	pPrev->next = pDelete->next;
	printf("Delete %s\n", pszKey);
	free(pDelete);
	return (ListObject->nSize--);
}

void ReleaseList(LIST_INFO* ListObject)
{
	NODE* pCurrent = ListObject->pHead;
	NODE* pDelete = NULL;
	while (pCurrent != NULL)
	{
		if (pCurrent == ListObject->pHead || pCurrent == ListObject->pTail)
			puts("Releasing Dummy");
		else
			printf("Releasing %s\n", pCurrent->pfGetKey(pCurrent->pData));
		pDelete = pCurrent;
		pCurrent = pCurrent->next;
		free(pDelete->pData);
		free(pDelete);
	}
	ListObject->pHead = NULL;
	ListObject->pTail = NULL;
	ListObject->nSize = 0;
	puts("List Successfully Released!\n");
}

int GetSize(LIST_INFO* ListObject)
{
	return (ListObject->nSize);
}

NODE* GetAt(LIST_INFO* ListObject, int idx)
{
	if (idx >= GetSize(ListObject))
		return (NULL);
	NODE* pCurrent = ListObject->pHead;
	for (int i = 0; i <= idx; ++i)
	{
		pCurrent = pCurrent->next;
	}
	return (pCurrent);
}
