#include "Stack.h"
#include "Queue.h"

void StackTest1()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	printf("%d\n", StackTop(&st));

	StackDestroy(&st);
}

void StackTest2()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	printf("%d ", StackTop(&st));
	StackPop(&st);
	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackPush(&st, 5);
	StackPush(&st, 6);

	//±È¿˙’ª
	while (!StackEmpety(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	StackDestroy(&st);
}

void QueueTest1()
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);

	printf("%d\n", QueueSize(&pq));
	QueuePop(&pq);
	QueuePop(&pq);

	while (!QueueEmpty(&pq))
	{
		printf("%d ", QueueHead(&pq));
		QueuePop(&pq);
	}
	printf("\n");

	QueueDestroy(&pq);
}

int main()
{
	//StackTest1();
	//StackTest2();
	QueueTest1();
	return 0;
}