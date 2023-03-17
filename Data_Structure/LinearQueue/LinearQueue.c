#include <stdio.h>
#include <stdlib.h>
#include "MyQueue.h"

void initQueue(QType* newQ)
{
	newQ->front = -1;
	newQ->rear = -1;
	newQ->qCap = 1;
	newQ->qData = (element*)calloc(newQ->qCap, sizeof(element));
}

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void qPrint(QType* newQ)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		//rear는 값을 가리키고, front는 맨 앞 값보다 하나 앞의 인덱스를 가리킴
		if (i <= newQ->front || i > newQ->rear)
			printf(" | ");
		else
			printf("%s | ", newQ->qData[i]);
	}
	putchar('\n');
}

int isEmpty(QType* newQ)
{
	if (newQ->rear == newQ->front)
		return (1);
	else
		return (0);
}

int isFull(QType* newQ)
{
	if (newQ->rear == newQ->qCap - 1)
		return (1);
	else
		return (0);
}

void enqueue(QType* newQ, element item)
{
	element* isNull = newQ->qData;
	if (isFull(newQ))
	{
		newQ->qCap *= 2;
		if (newQ->qCap > MAX_SIZE)
			error("Queue is at max size");
		newQ->qData = realloc(newQ->qData, sizeof(element) * newQ->qCap);
		if (newQ->qData == NULL)
		{
			free(isNull);
			error("memory realloc failed");
		}
		newQ->qData[++(newQ->rear)] = item;
	}
	else
		newQ->qData[++(newQ->rear)] = item;
}

element dequeue(QType* newQ)
{
	if (isEmpty(newQ))
		error("Queue is empty!");
	return (newQ->qData[++(newQ->front)]);
}

element peek(QType* newQ)
{
	if (isEmpty(newQ))
		error("Queue is empty!");
	return (newQ->qData[(newQ->front) + 1]);
}

