#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyQueue.h"


typedef struct USERDATA
{
	char ID[100];
	char PassWord[100];
	char Email[100];
	char szName[50];
}USERDATA;


const char* GetKey(USERDATA* pUser)
{
	return (pUser->ID);
}

USERDATA* CreateUserData(const char* ID, const char* PW, const char* Email, const char* name)
{
	USERDATA* pNewUser = (USERDATA*)malloc(sizeof(USERDATA));
	if (pNewUser == NULL)
		return (NULL);
	memset(pNewUser, 0, sizeof(USERDATA));
	strcpy_s(pNewUser->ID, sizeof(pNewUser->ID), ID);
	strcpy_s(pNewUser->PassWord, sizeof(pNewUser->PassWord), PW);
	strcpy_s(pNewUser->Email, sizeof(pNewUser->Email), Email);
	strcpy_s(pNewUser->szName, sizeof(pNewUser->szName), name);
	return (pNewUser);
}

void PrintList(LIST_INFO* ListObject)
{
	NODE* pCurrent = ListObject->pHead;
	USERDATA* pUserData = NULL;
	while (pCurrent != NULL)
	{
		if (pCurrent == ListObject->pHead || pCurrent == ListObject->pTail)
			puts("DUMMY\n");
		else
		{
			pUserData = (USERDATA*)pCurrent->pData;
			printf("User ID: %s, PassWord: %s, Email: %s, User Name: %s\n",
				pUserData->ID, pUserData->PassWord, pUserData->Email, pUserData->szName);
		}
		pCurrent = pCurrent->next;
	}
}

int main(void)
{
	LIST_INFO userData01 = { 0 };
	USERDATA* pNewUser = NULL;
	USERDATA DeqData;
	InitList(&userData01);
	pNewUser = CreateUserData("dndn1234", "abcdabcd012", "dndn123@naver.com", "Choi");
	Enqueue(&userData01, pNewUser, GetKey);
	pNewUser = CreateUserData("user01", "pw01", "user01@naver.com", "userone");
	Enqueue(&userData01, pNewUser, GetKey);
	pNewUser = CreateUserData("user02", "pw02", "user02@naver.com", "usertwo");
	Enqueue(&userData01, pNewUser, GetKey);
	pNewUser = CreateUserData("user03", "pw03", "user03@naver.com", "userthree");
	Enqueue(&userData01, pNewUser, GetKey);
	pNewUser = CreateUserData("user04", "pw04", "user04@naver.com", "userfour");
	Enqueue(&userData01, pNewUser, GetKey);
	pNewUser = CreateUserData("user05", "pw05", "user05@naver.com", "userfive");
	Enqueue(&userData01, pNewUser, GetKey);

	PrintList(&userData01);
	Dequeue(&userData01, &DeqData);
	printf("Dequeue user: %s, name: %s\n", DeqData.ID, DeqData.szName);
	Dequeue(&userData01, &DeqData);
	printf("Dequeue user: %s, name: %s\n", DeqData.ID, DeqData.szName);
	Dequeue(&userData01, &DeqData);
	printf("Dequeue user: %s, name: %s\n", DeqData.ID, DeqData.szName);
	USERDATA* GetData = (USERDATA*)(GetAt(&userData01, 2));
	printf("Name: %s\n", GetData->szName);


	PrintList(&userData01);
	ReleaseList(&userData01);
	return (0);
}
