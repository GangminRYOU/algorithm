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
int InsertBefore(LIST_INFO* ListObject, NODE* pDstNode, void* pParam, const char* (*U_GetKey)(void*));
int InsertAfter(LIST_INFO* ListObject, NODE* pDstNode, void* pParam, const char* (*U_GetKey)(void*));
int InsertAtHead(LIST_INFO* ListObject, void* pParam, const char* (*U_GetKey)(void*));
int InsertAtTail(LIST_INFO* ListObject, void* pParam, const char* (*U_GetKey)(void*));
int PushData(LIST_INFO* ListObject, void* pParam, const char* (*U_GetKey)(void*));
int PopData(LIST_INFO* ListObject, void* pParam);
NODE* FindPrev(LIST_INFO* ListObject, const char* pszKey);
NODE* FindNode(LIST_INFO* ListObject, const char* pszKey);
int DeleteNode(LIST_INFO* ListObject, const char* pszKey);
void ReleaseList(LIST_INFO* ListObject);
int GetSize(LIST_INFO* ListObject);
NODE* GetAt(LIST_INFO* ListObject, int idx);
