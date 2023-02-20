#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyStack.h"

typedef struct BOOKDATA
{
	char Book_Name[100];
	char AuthorName[64];
	int bPrice;
}BOOKDATA;

const char* GetKey(BOOKDATA* pParam)
{
	return (pParam->Book_Name);
}


BOOKDATA* CreateNewData(const char* bName, const char* aName, int price)
{
	BOOKDATA* pNewData = (BOOKDATA*)malloc(sizeof(BOOKDATA));
	if (pNewData == NULL)
		return (NULL);
	memset(pNewData, 0, sizeof(BOOKDATA));
	strcpy_s(pNewData->Book_Name, sizeof(pNewData->Book_Name), bName);
	strcpy_s(pNewData->AuthorName, sizeof(pNewData->AuthorName), aName);
	pNewData->bPrice = price;
	return (pNewData);
}

void PrintList(LIST_INFO* ListObject)
{
	NODE* pCurrent = ListObject->pHead;
	BOOKDATA* pDataPrint = NULL;
	while (pCurrent != NULL)
	{
		if (pCurrent == ListObject->pHead || pCurrent == ListObject->pTail)
			puts("DUMMY\n");
		else
		{
			pDataPrint = (BOOKDATA*)pCurrent->pData;
			printf("Book Name: %s, Author Name: %s, Price: %d\n",
				pDataPrint->Book_Name, pDataPrint->AuthorName, pDataPrint->bPrice);
		}
		pCurrent = pCurrent->next;
	}
}

int main(void)
{
	LIST_INFO BookList01 = { 0 };
	InitList(&BookList01);
	BOOKDATA* NovelData = NULL;
	BOOKDATA PopVar = { 0 };

	NovelData = CreateNewData("Lord of the rings", "James Cameron", 14500);
	PushData(&BookList01, NovelData, GetKey);
	NovelData = CreateNewData("Learning Data Structure with C", "Park", 22500);
	PushData(&BookList01, NovelData, GetKey);
	NovelData = CreateNewData("This is C++", "Choi Ho Sung", 20500);
	PushData(&BookList01, NovelData, GetKey);
	NovelData = CreateNewData("What is Justice", "Chris Paul", 14500);
	PushData(&BookList01, NovelData, GetKey);
	NovelData = CreateNewData("The Dialogue with God", "Hose Philipes", 12500);
	PushData(&BookList01, NovelData, GetKey);
	NovelData = CreateNewData("Data Management", "Gangmin RYOU", 1500);
	PushData(&BookList01, NovelData, GetKey);

	PrintList(&BookList01);

	PopData(&BookList01, &PopVar);
	printf("%s, %s, %d\n", PopVar.Book_Name, PopVar.AuthorName, PopVar.bPrice);
	PopData(&BookList01, &PopVar);
	printf("%s, %s, %d\n", PopVar.Book_Name, PopVar.AuthorName, PopVar.bPrice);
	PrintList(&BookList01);
	LIST_INFO BookList02;
	InitList(&BookList02);
	NovelData = CreateNewData("BookName01", "Author01", 1000);
	PushData(&BookList02, NovelData, GetKey);
	NovelData = CreateNewData("BookName02", "Author02", 2000);
	PushData(&BookList02, NovelData, GetKey);
	NovelData = CreateNewData("BookName03", "Author03", 3000);
	PushData(&BookList02, NovelData, GetKey);
	NovelData = CreateNewData("BookName04", "Author04", 4000);
	PushData(&BookList02, NovelData, GetKey);
	NovelData = CreateNewData("BookName05", "Author05", 5000);
	PushData(&BookList02, NovelData, GetKey);
	
	PrintList(&BookList02);
	PopData(&BookList02, &PopVar);
	printf("%s, %s, %d\n", PopVar.Book_Name, PopVar.AuthorName, PopVar.bPrice);
	PopData(&BookList02, &PopVar);
	printf("%s, %s, %d\n", PopVar.Book_Name, PopVar.AuthorName, PopVar.bPrice);
	PrintList(&BookList02);
	
	

	PrintList(&BookList01);
	ReleaseList(&BookList01);
	PrintList(&BookList02);
	ReleaseList(&BookList02);
	return (0);
}
