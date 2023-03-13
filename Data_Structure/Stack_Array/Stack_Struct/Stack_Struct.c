#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100
typedef struct s_Element
{
	int nStudent;
	char szName[MAX_STRING];
	char szAddress[MAX_STRING];
}Element;

Element eStack[MAX_STACK_SIZE];
int top = -1;

int isFull()
{
	return (top == MAX_STACK_SIZE - 1);
}

int isEmpty()
{
	return (top == -1);
}

void sPush(Element item)
{
	if (isFull())
	{
		fprintf(stderr, "Stack is full\n");
	}
	else
		eStack[++top] = item;
}

Element sPop(void)
{
	if (isEmpty())
	{
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else
		return (eStack[top--]);
}

Element sPeek(void)
{
	if (isEmpty())
	{
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else
		return (eStack[top]);
}

int main(void)
{
	Element sElement;
	Element sReturn;
	sElement.nStudent = 20190001;
	strcpy_s(sElement.szName, sizeof(sElement.szName), "Gangmin RYOU");
	strcpy_s(sElement.szAddress, sizeof(sElement.szAddress), "Uiwang-si");
	sPush(sElement);
	sReturn = sPop();
	printf("%s's id number is %d, and address is %s\n", sReturn.szName, sReturn.nStudent
		, sReturn.szAddress);
	return (0);
}
