#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MyQueue.h"

//자료구조를 만드는 사람 입장
int InitList(LIST_INFO* ListObject)
{
	ListObject->pHead = (NODE*)malloc(sizeof(NODE));
	if (ListObject->pHead == NULL)
		return (0);
	ListObject->pTail = (NODE*)malloc(sizeof(NODE));
	if (ListObject->pTail == NULL)
		return (0);
	memset(ListObject->pHead, 0, sizeof(NODE));
	memset(ListObject->pTail, 0, sizeof(NODE));

	ListObject->pHead->next = ListObject->pTail;
	ListObject->nSize = 0;
	return (1);
}

const NODE* FindPrev(LIST_INFO* ListObject, const char* pszKey)
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

const NODE* FindNode(LIST_INFO* ListObject, const char* pszKey)
{
	NODE* pPrev = FindPrev(ListObject, pszKey);
	if (pPrev == NULL)
		return (NULL);
	NODE* pCurrent = pPrev->next;
	return (pCurrent);
}

int InsertBefore(LIST_INFO* ListObject, NODE* pDstNode, void* pParam, const char* (GetKey)(void*))
{
	NODE* pPrev = ListObject->pHead;
	while (pPrev->next != pDstNode)
		pPrev = pPrev->next;
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	if (pNewNode == NULL)
		return (0);
	memset(pNewNode, 0, sizeof(NODE));
	pNewNode->pData = pParam;
	pNewNode->pfGetKey = GetKey;

	pNewNode->next = pDstNode;
	pPrev->next = pNewNode;
	return (ListObject->nSize++);
}

int InsertAfter(LIST_INFO* ListObject, NODE* pDstNode, void* pParam, const char* (*GetKey)(void*))
{
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	if (pNewNode == NULL)
		return (0);
	memset(pNewNode, 0, sizeof(NODE));
	pNewNode->pData = pParam;
	pNewNode->pfGetKey = GetKey;
	
	pNewNode->next = pDstNode->next;
	pDstNode->next = pNewNode;
	return (ListObject->nSize++);
}

int InsertAtHead(LIST_INFO* ListObject, void* pParam, const char* (*GetKey)(void*))
{
	return (InsertAfter(ListObject, ListObject->pHead, pParam, GetKey));
}

int InsertAtTail(LIST_INFO* ListObject, void* pParam, const char* (*GetKey)(void*))
{
	return (InsertBefore(ListObject, ListObject->pTail, pParam, GetKey));
}

int DeleteNode(LIST_INFO* ListObject, const char* pszKey)
{
	NODE* pPrev = FindPrev(ListObject, pszKey);
	NODE* pDstNode = pPrev->next;
	pPrev->next = pDstNode->next;
	printf("Deleting %s's Information\n", pDstNode->pfGetKey(pDstNode->pData));
	free(pDstNode->pData);
	free(pDstNode);
}

int Enqueue(LIST_INFO* ListObject, void* pParam, const char* (*GetKey)(void*))
{
	return (InsertAtTail(ListObject, pParam, GetKey));
}

int Dequeue(LIST_INFO* ListObject, void* pParam)
{
	NODE* pFstNode = ListObject->pHead->next;
	ListObject->pHead->next = pFstNode->next;
	
	memcpy(pParam, pFstNode->pData, _msize(pFstNode->pData));
	printf("Dequeing %s's information\n", pFstNode->pfGetKey(pFstNode->pData));
	free(pFstNode->pData);
	free(pFstNode);
}


void ReleaseList(LIST_INFO* ListObject)
{
	NODE* pCurrent = ListObject->pHead;
	NODE* pDelete = NULL;
	while (pCurrent != NULL)
	{
		if (pCurrent == ListObject->pHead || pCurrent == ListObject->pTail)
			puts("Releasing Dummy\n");
		else
			printf("Releasing %s's information\n", pCurrent->pfGetKey(pCurrent->pData));
		pDelete = pCurrent;
		pCurrent = pCurrent->next;
		free(pDelete->pData);
		free(pDelete);
	}
	puts("List Sucessfully Released!\n");
}

int GetSize(LIST_INFO* ListObject)
{
	return (ListObject->nSize);
}

const void* GetAt(LIST_INFO* ListObject, int idx)
{
	if (idx >= ListObject->nSize)
		return (NULL);
	NODE* pCurrent = ListObject->pHead;
	for (int i = 0; i <= idx; ++i)
	{
		pCurrent = pCurrent->next;
	}
	return (pCurrent->pData);
}
