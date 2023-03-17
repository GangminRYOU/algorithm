#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Deque_Array.h"


void error(char* pMessage)
{
	fprintf(stderr, "%s\n", pMessage);
	exit(-1);
}

void initDeque(DQtype* newDQ)
{
	newDQ->qCount = 0;
	newDQ->front = 0;
	newDQ->rear = 0;
}

int isEmpty(DQtype* newDQ)
{
	if (newDQ->front == newDQ->rear)
		return (1);
	else
		return (0);
}

int isFull(DQtype* newDQ)
{
	if ((newDQ->rear + 1) % MAX_QUEUE_SIZE == newDQ->front)
		return (1);
	else
		return (0);
}

void AddRear(DQtype* newDQ, element dqItem)
{
	if (isFull(newDQ))
		error("Queus is full!");
	newDQ->rear = (newDQ->rear + 1) % MAX_QUEUE_SIZE;
	newDQ->qData[newDQ->rear] = dqItem;
	newDQ->qCount++;
}

void AddFront(DQtype* newDQ, element dqItem)
{
	if (isFull(newDQ))
		error("Queus is full!");
	newDQ->qData[newDQ->front] = dqItem;
	newDQ->front = (newDQ->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element DeleteFront(DQtype* newDQ)
{
	if (isEmpty(newDQ))
		error("Queue is Empty!");
	newDQ->front = (newDQ->front + 1) % MAX_QUEUE_SIZE;
	newDQ->qCount--;
	return (newDQ->qData[newDQ->front]);
}

element DeleteRear(DQtype* newDQ)
{
	element retDQ;
	if (isEmpty(newDQ))
		error("Queue is Empty!");
	retDQ = newDQ->qData[newDQ->rear];
	newDQ->rear = (newDQ->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return (retDQ);
}

element GetFront(DQtype* newDQ)
{
	if (isEmpty(newDQ))
		error("Queue is Empty!");
	return (newDQ->qData[(newDQ->front + 1) % MAX_QUEUE_SIZE]);
}

element GetRear(DQtype* newDQ)
{
	if (isEmpty(newDQ))
		error("Queue is Empty!");
	return (newDQ->qData[(newDQ->rear) % MAX_QUEUE_SIZE]);
}

