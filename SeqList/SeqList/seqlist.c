#include "seqlist.h"

void SeqListInit(SL* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("Init Fail\n");
		exit(-1);
	}
	ps->size =  0;
	ps->capacity = 4;
}

void CheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;
	}
	
	//SL* tmp = (SL*)realloc(ps->a, sizeof(SL) * ps->capacity);
	SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
	if (tmp == NULL)
	{
		printf("Expansion Fail\n");
		exit(-1);
	}
	ps->a = tmp;
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	/*CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;*/

	SeqListPosInsert(ps, ps->size, x);
}

void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	/*CheckCapacity(ps);
	int end = ps->size - 1;
	while(end>=0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;*/

	SeqListPosInsert(ps, 0, x);
}

void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);
	for (int i = 1; i < ps->size; i++)
	{
		ps->a[i - 1] = ps->a[i];
	}
	ps->size--;
}

int SeqListFind(SL* ps, SLDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i; //找到返回x的下标
		}
	}
	return -1; //未找到
}

void SeqListPosInsert(SL* ps, int pos, SLDataType x)
{
	assert(pos >= 0 && pos <= ps->size);

	CheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListPosErase(SL* ps, int pos)
{
	assert(pos >= 0 && pos < ps->size);

	if (pos == ps->size - 1)
	{
		SeqListPopBack(ps);
	}
	else
	{
		for (int i = pos + 1; i < ps->size; i++)
		{
			ps->a[i - 1] = ps->a[i];
		}
		ps->size--;
	}
}

void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}

void SeqListDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
}