#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 6


typedef struct element
{
	int stdID;
	char szName[20];
	char szAddress[100];
}element;

typedef struct Qtype {
	int qCount;
	int qCap;
	int front;
	int rear;
	element qData[MAX_QUEUE_SIZE];
}Qtype;

void error(char* pMessage)
{
	fprintf(stderr, "%s\n", pMessage);
	exit(-1);
}

void initQueue(Qtype* newQ)
{
	newQ->qCount = 0;
	newQ->qCap = 1;
	newQ->front = 0;
	newQ->rear = 0;
}

int isEmpty(Qtype* newQ)
{
	if (newQ->front == newQ->rear)
		return (1);
	else
		return (0);
}

int isFull(Qtype* newQ)
{
	if ((newQ->rear + 1) % MAX_QUEUE_SIZE == newQ->front)
		return (1);
	else
		return (0);
}

void Enqueue(Qtype* newQ, element qItem)
{
	if (isFull(newQ))
		error("Queus is full!");
	newQ->rear = (newQ->rear + 1) % MAX_QUEUE_SIZE;
	newQ->qData[newQ->rear] = qItem;
	newQ->qCount++;
}

element Dequeue(Qtype* newQ)
{
	if (isEmpty(newQ))
		error("Queue is Empty!");
	newQ->front = (newQ->front + 1) % MAX_QUEUE_SIZE;
	newQ->qCount--;
	return (newQ->qData[newQ->front]);
}

element Peek(Qtype* newQ)
{
	if (isEmpty(newQ))
		error("Queue is Empty!");
	return (newQ->qData[(newQ->front + 1) % MAX_QUEUE_SIZE]);
}

void PrintQueue(Qtype* newQ)
{
	int i;
	if (isEmpty(newQ))
		error("No Items to print!");
	printf("front: %d, rear: %d\n", newQ->front, newQ->rear);
	i = (newQ->front + 1) % MAX_QUEUE_SIZE;
	while (i != newQ->rear)
	{
		printf("Student Name: %s |\t", newQ->qData[i].szName);
		printf("Student ID: %d |\t", newQ->qData[i].stdID);
		printf("Student Address: %s |\t", newQ->qData[i].szAddress);
		putchar('\n');
		i = (i + 1) % MAX_QUEUE_SIZE;
	}
	printf("Student Name: %s |\t", newQ->qData[i].szName);
	printf("Student ID: %d |\t", newQ->qData[i].stdID);
	printf("Student Address: %s |\t", newQ->qData[i].szAddress);
	putchar('\n');
}

void PutInfo(element* item, char* nameParam, int idParam, char* addrParam)
{
	strcpy_s(item->szName, sizeof(item->szName), nameParam);
	strcpy_s(item->szAddress, sizeof(item->szAddress), addrParam);
	item->stdID = idParam;
}

int main(void)
{
	Qtype newQ;
	element stdInfo;
	initQueue(&newQ);
	PutInfo(&stdInfo, "Gangmin", 20478322, "Uiwang-si");
	Enqueue(&newQ, stdInfo);
	PrintQueue(&newQ);
	PutInfo(&stdInfo, "Hyunseok", 86221213, "Uiwang-si");
	Enqueue(&newQ, stdInfo);
	PrintQueue(&newQ);
	PutInfo(&stdInfo, "Haeun", 28310231, "Guacheon-si");
	Enqueue(&newQ, stdInfo);
	PrintQueue(&newQ);
	PutInfo(&stdInfo, "Minsoo", 12314122, "Bundang-si");
	Enqueue(&newQ, stdInfo);
	PrintQueue(&newQ);
	PutInfo(&stdInfo, "Sieun", 13841231, "Kyeongju-si");
	Enqueue(&newQ, stdInfo);
	PrintQueue(&newQ);
	stdInfo = Dequeue(&newQ);
	printf("Deleted %s's data!\n", stdInfo.szName);
	stdInfo = Dequeue(&newQ);
	printf("Deleted %s's data!\n", stdInfo.szName);
	printf("Current Queue size is %d\n", newQ.qCount);
	PrintQueue(&newQ);
	PutInfo(&stdInfo, "Gangmin", 20478322, "Uiwang-si");
	Enqueue(&newQ, stdInfo);
	PrintQueue(&newQ);
	PutInfo(&stdInfo, "Hyunseok", 86221213, "Uiwang-si");
	Enqueue(&newQ, stdInfo);
	PrintQueue(&newQ);
	return (0);
}
