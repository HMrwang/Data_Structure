#include "List.h"

ListNode* CreateNewNode()
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		printf("CreateNewNode Fail\n");
		exit(-1);
	}
	newnode->prev = NULL;
	newnode->next = NULL;

	return newnode;
}

ListNode* ListInit()
{
	ListNode* phead = CreateNewNode();
	
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void ListPrint(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;

	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	/*ListNode* tail = phead->prev;
	ListNode* newnode = CreateNewNode();
	newnode->data = x;

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/

	ListInsert(phead, x);
}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	/*ListNode* tail = phead->prev;
	phead->prev = tail->prev;
	tail->prev->next = phead;

	free(tail);*/

	ListErase(phead->prev);
}

void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	/*ListNode* newnode = CreateNewNode();
	newnode->data = x;

	newnode->next = phead->next;
	newnode->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;*/

	ListInsert(phead->next, x);
}

void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	/*ListNode* popnode = phead->next;
	phead->next = popnode->next;
	popnode->next->prev = phead;

	free(popnode);*/

	ListErase(phead->next);
}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
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

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* newnode = CreateNewNode();
	newnode->data = x;

	ListNode* posPrev = pos->prev;
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
}

void ListDestroy(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}