#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE
{
	char szName[64];
	char szPhone[64];
	struct NODE* left;
	struct NODE* right;
}NODE;

NODE* g_pRoot = NULL;

void PrintTree(NODE* pParent)
{
	if (pParent == NULL)
		return;
	PrintTree(pParent->left);
	printf("Name %s, Phone: %s\n", pParent->szName, pParent->szPhone);
	PrintTree(pParent->right);
}

void ReleaseTree(NODE* pParent)
{
	if (pParent == NULL)
		return;
	ReleaseTree(pParent->left);
	ReleaseTree(pParent->right);
	printf("Deleting %s info\n", pParent->szName);
	free(pParent);
}

NODE* FindParent(const char* pszKey)
{
	NODE* pTmp = g_pRoot;
	NODE* pPrev = g_pRoot;
	while (pTmp != NULL)
	{
		if (strcmp(pTmp->szPhone, pszKey) == 0)
			break;
		else if (strcmp(pTmp->szPhone, pszKey) > 0)
		{
			pPrev = pTmp;
			pTmp = pTmp->left;
			continue;
		}
		else
		{
			pPrev = pTmp;
			pTmp = pTmp->right;
			continue;
		}
	}
	return (pPrev);
}

NODE* FindNode(NODE* pParent, const char* pszKey)
{
	if (pParent == NULL)
		return(NULL);
	if (strcmp(pParent->szPhone, pszKey) == 0)
		return (pParent);
	else if(strcmp(pParent->szPhone, pszKey) > 0)
		FindNode(pParent->left, pszKey);
	else
		FindNode(pParent->right, pszKey);
}

//만약 매개변수를 NODE*로 받으면 더 재사용가능한 코드가 될듯
int DeleteNode(const char* pszKey)
{
	NODE* pTmp = FindNode(g_pRoot, pszKey);
	NODE* pParent = FindParent(pszKey);
	NODE* RightEmpty = g_pRoot;
	if (pTmp == NULL)
		return (0);
	if (pTmp == g_pRoot)
		g_pRoot = pTmp->left;
	//삭제할 노드의 자식노드가 둘다 있는 경우
	if (pTmp->left != NULL && pTmp->right != NULL)
	{
		RightEmpty = pTmp->left;
		while (RightEmpty->right != NULL)
			RightEmpty = RightEmpty->right;
		RightEmpty->right = pTmp->right;
		//부모 노드의 어느 쪽에 있는지 확인
		if (pTmp == pParent->left)
			pParent->left = pTmp->left;
		else if (pTmp == pParent->right)
			pParent->right = pTmp->left;
	}
	//삭제할 노드의 자식노드가 한개거나 없는 경우
	else
	{
		if (pTmp->left != NULL)
		{
			if (pTmp == pParent->left)
				pParent->left = pTmp->left;
			else if (pTmp == pParent->right)
				pParent->right = pTmp->left;
		}
		else
		{
			if (pTmp == pParent->left)
				pParent->left = pTmp->right;
			else if (pTmp == pParent->right)
				pParent->right = pTmp->right;
		}
	}
	printf("Deleting %s's info\n", pTmp->szName);
	free(pTmp);
}

int InsertNode(const char *pszName, const char *pszPhone)
{
	NODE* pNewNode = (NODE*)malloc(sizeof(NODE));
	if (pNewNode == NULL)
		return (0);
	memset(pNewNode, 0, sizeof(NODE));
	strcpy_s(pNewNode->szName, sizeof(pNewNode->szName), pszName);
	strcpy_s(pNewNode->szPhone, sizeof(pNewNode->szPhone), pszPhone);

	if (g_pRoot == NULL)
	{
		g_pRoot = pNewNode;
		return (1);
	}
	else
	{
		NODE* pTmp = g_pRoot;
		while (pTmp != NULL)
		{
			if (strcmp(pTmp->szPhone, pNewNode->szPhone) > 0)
			{
				if (pTmp->left == NULL)
				{
					pTmp->left = pNewNode;
					break;
				}
				else
				{
					pTmp = pTmp->left;
					continue;
				}
			}
			else
			{
				if (pTmp->right == NULL)
				{
					pTmp->right = pNewNode;
					break;
				}
				else
				{
					pTmp = pTmp->right;
					continue;
				}
			}
		}
	}
	return (1);
}

int main(void)
{
	InsertNode("Gangmin", "4");
	InsertNode("Sanghyuk", "2");
	InsertNode("Uizhong", "6");
	InsertNode("Minchan", "1");
	InsertNode("ABDD", "3");
	InsertNode("CCER", "5");
	InsertNode("CRUD", "8");
	InsertNode("GFEW", "7");
	InsertNode("GaFWF", "9");
	PrintTree(g_pRoot);
	NODE* pPrint = FindNode(g_pRoot, "9");
	printf("%s, %s\n", pPrint->szName, pPrint->szPhone);
	DeleteNode("6");
	PrintTree(g_pRoot);
	ReleaseTree(g_pRoot);
	return (0);
}
