#pragma once

typedef struct NODE
{
	const char* (*pfGetKey)(void*);
	void* pData;
	struct NODE* next;
}NODE;


typedef struct LIST_INFO
{
	NODE* pHead;
	NODE* pTail;
	int		nSize;
}LIST_INFO;

int InitList(LIST_INFO* ListObject);
const NODE* FindPrev(LIST_INFO* ListObject, const char* pszKey);
const NODE* FindNode(LIST_INFO* ListObject, const char* pszKey);
int InsertBefore(LIST_INFO* ListObject, NODE* pDstNode, void* pParam, const char* (GetKey)(void*));
int InsertAfter(LIST_INFO* ListObject, NODE* pDstNode, void* pParam, const char* (*GetKey)(void*));
int InsertAtHead(LIST_INFO* ListObject, void* pParam, const char* (*GetKey)(void*));
int InsertAtTail(LIST_INFO* ListObject, void* pParam, const char* (*GetKey)(void*));
int DeleteNode(LIST_INFO* ListObject, const char* pszKey);
int Enqueue(LIST_INFO* ListObject, void* pParam, const char* (*GetKey)(void*));
int Dequeue(LIST_INFO* ListObject, void* pParam);
void ReleaseList(LIST_INFO* ListObject);
int GetSize(LIST_INFO* ListObject);
const void* GetAt(LIST_INFO* ListObject, int idx);
