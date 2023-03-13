#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int element;
typedef struct s_StackType
{
	int sTop;
	element stack[MAX_SIZE];
}StackType;

//스택 초기화함수
void initStack(StackType *sInstance)
{
	sInstance->sTop = -1;
}

int isEmpty(StackType* sInstance)
{
	return(sInstance->sTop == -1);
}

int isFull(StackType* sInstance)
{
	return(sInstance->sTop == MAX_SIZE - 1);
}

void sPush(StackType* sInstance, element item)
{
	if (isFull(sInstance))
		fprintf(stderr, "Stack is full\n");
	else
		sInstance->stack[++(sInstance->sTop)] = item;
}
element sPop(StackType* sInstance)
{
	if (isEmpty(sInstance))
	{
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else
		return (sInstance->stack[(sInstance->sTop)--]);
}
element sPeek(StackType* sInstance)
{
	if (isEmpty(sInstance))
	{
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else
		return (sInstance->stack[sInstance->sTop]);
}

int main(void)
{
	StackType sStack;
	element sNumber;

	initStack(&sStack);
	sPush(&sStack, 9);
	sPush(&sStack, 8);
	sPush(&sStack, 7);
	sPush(&sStack, 6);
	sPush(&sStack, 5);
	sPush(&sStack, 4);
	sPush(&sStack, 3);
	sPush(&sStack, 2);
	sPush(&sStack, 1);
	while (sStack.sTop >= -1)
	{
		sNumber = sPop(&sStack);
		printf("popped data is%d\n", sNumber);
	}
	return (0);
}
