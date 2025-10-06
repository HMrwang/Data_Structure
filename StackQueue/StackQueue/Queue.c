#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("Create Node Fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;

	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
}

int QueueSize(Queue* pq)
{
	assert(pq);

	int size = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}

	return size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL;
}

QDataType QueueHead(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}

QDataType QueueTail(Queue* pq)
{
	assert(pq);
	assert(pq->tail);

	return pq->tail->data;
}