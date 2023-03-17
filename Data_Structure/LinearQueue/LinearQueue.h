#pragma once

#define MAX_SIZE 8

typedef struct element
{
	char szName[20];
}element;

typedef struct QueueType
{
	int front;
	int rear;
	int qCap;
	element* qData;
}QType;

void initQueue(QType* newQ);
void error(char* message);
void qPrint(QType* newQ);
int isEmpty(QType* newQ);
int isFull(QType* newQ);
void enqueue(QType* newQ, element item);
element dequeue(QType* newQ);
element peek(QType* newQ);

