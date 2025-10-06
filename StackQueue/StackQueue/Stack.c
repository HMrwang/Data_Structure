#include "Stack.h"

void StackInit(Stack* st)
{
	st->top = 0;
	st->capacity = 4;
	st->a = (STDataType*)malloc(sizeof(STDataType) * st->capacity);
	if (st->a == NULL)
	{
		printf("Init Fail\n");
		exit(-1);
	}
}

void StackDestroy(Stack* st)
{
	assert(st);

	free(st->a);
	st->a = NULL;
	st->capacity = st->top = 0;
}

void StackPush(Stack* st, STDataType x)
{
	assert(st);

	if (st->top == st->capacity) // À©ÈÝ
	{
		st->capacity *= 2;
		STDataType* tmp = (STDataType*)realloc(st->a, sizeof(STDataType) * st->capacity);
		if (tmp == NULL)
		{
			printf("Push Fail\n");
			exit(-1);
		}
		st->a = tmp;
	}

	st->a[st->top] = x;
	st->top++;
}

void StackPop(Stack* st)
{
	assert(st);
	assert(!StackEmpety(st));

	st->top--;
}

STDataType StackTop(Stack* st)
{
	assert(st);
	assert(!StackEmpety(st));

	return st->a[st->top - 1];
}

int StackSize(Stack* st)
{
	assert(st);

	return st->top;
}

bool StackEmpety(Stack* st)
{
	assert(st);

	return st->top == 0;
}