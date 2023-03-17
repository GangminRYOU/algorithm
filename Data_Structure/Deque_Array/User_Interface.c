#include "Deque_Array.h"
#include <stdio.h>

void PrintDeque(DQtype* newQ)
{
	int i;
	if (isEmpty(newQ))
		error("No Items to print!");
	printf("front: %d, rear: %d\n", newQ->front, newQ->rear);
	i = (newQ->front + 1) % MAX_QUEUE_SIZE;
	while (i != newQ->rear)
	{
		printf("%d | ", newQ->qData[i]);
		i = (i + 1) % MAX_QUEUE_SIZE;
	}
	printf("%d | ", newQ->qData[i]);
	putchar('\n');
}

int main(void)
{
	DQtype newDQ;
	initDeque(&newDQ);
	for (int i = 0; i < 3; ++i)
	{
		AddFront(&newDQ, i);
		PrintDeque(&newDQ);
	}
	for (int i = 0; i < 2; ++i)
	{
		DeleteRear(&newDQ);
		PrintDeque(&newDQ);
	}
	return (0);
}

