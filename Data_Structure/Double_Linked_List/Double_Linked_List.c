#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_ERROR "Error: Not Enough Memory"

typedef struct NODE {

	char szData[64];
	
	struct NODE* prev;
	struct NODE* next;
} NODE;

NODE* g_pHead;
NODE* g_pTail;
int g_nSize;

//Doubel Linked List에 들어가는 
//전역변수들을 초기화해주는 역할
void InitList(void)
{
	g_pHead = (NODE*)malloc(sizeof(NODE));
	g_pTail = (NODE*)malloc(sizeof(NODE));
	g_nSize = 0;
	if (g_pHead == 0 || g_pTail == 0)
	{
		puts(MEM_ERROR);
		return (0);
	}
	memset(g_pHead, 0, sizeof(NODE));
	memset(g_pTail, 0, sizeof(NODE));

	strcpy_s(g_pHead->szData, sizeof(g_pHead->szData), "DUMMY HEAD");
	strcpy_s(g_pTail->szData, sizeof(g_pTail->szData), "DUMMY TAIL");
	g_pHead->next = g_pTail;
	g_pTail->prev = g_pHead;
}

void ReleaseList(void)
{
	NODE* pTmp = g_pHead;
	while (pTmp != NULL)
	{
		NODE* pDelete = pTmp;
		pTmp = pTmp->next;
		printf("Deleting %s...\n", pDelete->szData);
		free(pDelete);
	}
	g_pHead = NULL;
	g_pTail = NULL;
	g_nSize = 0;
	puts("ReleaseList()");
}


void PrintList(void)
{
	printf("PrintList(): g_nSize [%d], g_pHead [%p], g_pTail [%p]\n", g_nSize, g_pHead, g_pTail);
	int i = 0;
	NODE* pTmp = g_pHead;
	while (pTmp != NULL)
	{
		if (pTmp->prev != 0 && pTmp->next != 0)
		{
			printf("Index: %d ", i);
			++i;
		}
		printf("[%p] %p, %s [%p]\n", pTmp->prev, pTmp, pTmp->szData, pTmp->next);
		pTmp = pTmp->next;
	}

}

//포인터에 있는 내용을 읽기만 하지 쓰진
//않으니까 const
//반환값을 int로 하면 성공실패 여부도
//알수 있지만, index반환을 시킬수도 있다.
int InsertAtHead(const char *pszData)
{
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	if (pNewNode == 0)
	{
		puts(MEM_ERROR);
		return (0);
	}
	memset(pNewNode, 0, sizeof(NODE));
	//strcpy에다가 포인터 변수로 해놓고 동적할당을 해주지 않았기 때문에
	//당연히 Error가 남 -> 배열로 변경
	strcpy_s(pNewNode->szData, sizeof(pNewNode->szData), pszData);
	
	//새 노드에 대한 교통정리
	pNewNode->prev = g_pHead;
	pNewNode->next = g_pHead->next;
	
	//기존 리스트의 포인터 정리
	g_pHead->next = pNewNode;
	pNewNode->next->prev = pNewNode;
	
	g_nSize++;
	return (g_nSize);
}

int InsertBefore(NODE* pDstNode, const char* pszData)
{
	NODE* pNode = (NODE*)malloc(sizeof(NODE));
	if (pNode == NULL)
	{
		puts(MEM_ERROR);
		return (0);
	}
	memset(pNode, 0, sizeof(NODE));
	strcpy_s(pNode->szData, sizeof(pNode->szData), pszData);
	
	pNode->next = pDstNode;
	pNode->prev = pDstNode->prev;

	pDstNode->prev->next = pNode;
	pDstNode->prev = pNode;
	
	g_nSize++;
	return (g_nSize);
}



int InsertAtTail(const char *pszData)
{
	InsertBefore(g_pTail, pszData);
	return (g_nSize);
}

//idx번째에 있는 NODE가 무엇이냐?
NODE* GetAt(int idx)
{
	NODE* current = g_pHead->next;
	for (int i = 0; i < idx; ++i)
	{
		if (idx >= g_nSize)
			return NULL;
		current = current->next;
	}
	return (current);
}

//idx를 기준으로 앞쪽에 붙여넣는다. 만약 2번째 idx에 붙여넣고 싶다면 2번쨰 idx노드를 뒤로 보내고
//앞에 Node를 붙여넣음
int InsertAt(int idx, const char *pszData)
{
	NODE* org_node = GetAt(idx);
	if (org_node == NULL)
	{
		puts("idx doesn't exist!\n");
		return (0);
	}
	InsertBefore(org_node, pszData);
	return (g_nSize);
}


NODE* FindNode(const char *pszData)
{
	//Double Linked List는 Dummy Head
	//Dummy Tail이 있기 때문에 지워질
	//Node의 앞, 뒤로 Node가 항상 있다.
	
	//데이터가 없을 경우 NULL반환
	if (g_pHead == NULL)
		return NULL;
	//g_pHead는 검색의 대상이 아니기 때문에
	//g_pHead->next부터 찾는다.
	NODE* pTmp = g_pHead->next;
	//마찬가지로 g_pTail Node도 검색의 대상
	//이 아니다.
	while (pTmp != g_pTail)
	{
		if (strcmp(pTmp->szData, pszData) == 0)
			return pTmp;
		pTmp = pTmp->next;
	}
	
	return NULL;
}

int DeleteNode(const char* pszData)
{
	NODE* pNode = FindNode(pszData);
	if (pNode == NULL)
		return (0);
	
	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;
	printf("Deleting [%p], %s\n", pNode, pNode->szData);
	free(pNode);
	puts("Deleted");

	g_nSize--;
	return (0);
}

//변수를 그냥 읽어도 되지만, 함수로
//만들어 두는게 객체지향적 코드로 갈때
//훨씬 더 의미가 있다.
int GetSize()
{
	return g_nSize;
}

int GetLength(void)
{
	return GetSize();
}

int IsEmpty(void)
{
	return GetSize();
}


int main(void)
{
	InitList();

	InsertAtTail("TEST01");
	InsertAtTail("TEST02");
	InsertAtTail("TEST03");

	InsertAt(0, "TEST AT 00");
	PrintList();

	InsertAt(2, "TEST AT 02");
	PrintList();

	InsertAt(4, "TEST AT 04");
	PrintList();

	//기존의 Node가 3개 였고, 뒤에 3개을 추가 했으니 총 Node는 6개
	//10번 idx는 존재하지 않는다. 그럼에도 값을 추가할 거냐?
	InsertAt(10, "TEST AT 10");
	PrintList();

	NODE* pNode = GetAt(0);
	if (pNode)
		printf("GetAt(%d): %s\n", 0, pNode->szData);
	else
		printf("GetAt(%d): %s\n", 0, "Not Found");
	pNode = GetAt(3);
	if (pNode)
		printf("GetAt(%d): %s\n", 3, pNode->szData);
	else
		printf("GetAt(%d): %s\n", 3, "Not Found");
	pNode = GetAt(6);
	if (pNode)
		printf("GetAt(%d): %s\n", 6, pNode->szData);
	else
		printf("GetAt(%d): %s\n", 6, "Not Found");
	pNode = GetAt(7);
	if (pNode)
		printf("GetAt(%d): %s\n", 7, pNode->szData);
	else
		printf("GetAt(%d): %s\n", 7, "Not Found");


	PrintList();
	ReleaseList();
	return (0);
	return (0);
}
