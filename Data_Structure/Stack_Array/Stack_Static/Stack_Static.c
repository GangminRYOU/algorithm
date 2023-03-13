#include <stdio.h>

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int isEmpty(void)
{
	return (top == -1);
}

int isFull(void)
{
	return (top == MAX_STACK_SIZE - 1);
}

void sPush(element item)
{
	if (isFull())
		fprintf(stderr, "Stack overflow\n");
	else
	{
		stack[++top] = item;
	}
}

element sPop(void)
{
	if (isEmpty())
	{
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else
	{
		return (stack[top--]);
	}
}

element sPeek(void)
{
	if (isEmpty())
	{
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else
		return (stack[top]);
}

int main(void)
{
	int retValue;
	sPush(1);
	sPush(2);
	sPush(3);
	sPush(4);
	sPush(5);
	sPush(6);
	while (top >= 3)
	{
		retValue = sPop();
		printf("popped value is %d\n", retValue);
	}
	printf("peeked value is %d\n", retValue = sPeek());
	return (0);
}
