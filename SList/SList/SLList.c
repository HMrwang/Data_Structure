#include "SLList.h"

SLLNode* CreateListNode(SLLDataType x)
{
	SLLNode* newnode = (SLLNode*)malloc(sizeof(SLLNode));
	if (newnode == NULL)
	{
		printf("CreateListNode Fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}


void SLListPrint(SLLNode* phead)
{
	SLLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SLListPushBack(SLLNode** pphead, SLLDataType x)
{
	assert(pphead);

	SLLNode* newnode = CreateListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找到尾节点
		SLLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SLListPushFront(SLLNode** pphead, SLLDataType x)
{
	assert(pphead);

	SLLNode* newnode = CreateListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

void SLListPopBack(SLLNode** pphead)
{
	assert(*pphead);

	//只有一个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//两个及以上节点
	else
	{
		SLLNode* tail = *pphead;
		SLLNode* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;

		free(tail);
		tail = NULL;
	}
}

void SLListPopFront(SLLNode** pphead)
{
	assert(*pphead);

	SLLNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLLNode* SLListFind(SLLNode* phead, SLLDataType x)
{
	assert(phead);

	SLLNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	
	return NULL;
}

//在pos节点前插入一个新节点
void SLListInsert(SLLNode** pphead, SLLNode* pos, SLLDataType x)
{
	assert(pphead);
	assert(pos);

	SLLNode* newnode = CreateListNode(x);
	
	//pos为第一个节点
	if (pos == *pphead)
	{
		newnode->next = pos;
		*pphead = newnode;
	}
	else
	{
		SLLNode* prev_pos = *pphead;
		while (prev_pos->next != pos)
		{
			prev_pos = prev_pos->next;
		}
		prev_pos->next = newnode;
		newnode->next = pos;
	}
}

void SLListInsertAfter(SLLNode* pos, SLLDataType x)
{
	assert(pos);
	
	SLLNode* newnode = CreateListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLListErase(SLLNode** pphead, SLLNode* pos)
{
	assert(pphead);
	assert(pos);

	if (pos == *pphead)
	{
		*pphead = pos->next;
	}
	else
	{
		SLLNode* prev_pos = *pphead;
		while (prev_pos->next != pos)
		{
			prev_pos = prev_pos->next;
		}
		prev_pos->next = pos->next;
	}

	free(pos);
	//pos = NULL;
}

void SLListEraseAfter(SLLNode* pos)
{
	assert(pos->next);

	SLLNode* next = pos->next;
	pos->next = next->next;
	free(next);
	//next = NULL;
}

void SLListDestroy(SLLNode** pphead)
{
	assert(pphead);

	SLLNode* cur = *pphead;
	while (cur)
	{
		SLLNode* next = cur->next;
		free(cur);
		cur=next;
	}

	*pphead = NULL;
}
