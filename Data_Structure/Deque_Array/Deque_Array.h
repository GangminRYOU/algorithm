#pragma once

#pragma once

#define MAX_QUEUE_SIZE 10

typedef int element;

typedef struct DQtype {
	int qCount;
	int front;
	int rear;
	element qData[MAX_QUEUE_SIZE];
}DQtype;

void error(char* pMessage);
void initDeque(DQtype* newDQ);
int isEmpty(DQtype* newDQ);
int isFull(DQtype* newDQ);
void AddRear(DQtype* newDQ, element dqItem);
element DeleteFront(DQtype* newDQ);
element GetFront(DQtype* newDQ);
element GetRear(DQtype* newDQ);
element DeleteRear(DQtype* newDQ);
void AddFront(DQtype* newDQ, element dqItem);
