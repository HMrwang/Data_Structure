//带头双向循环链表
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

ListNode* ListInit();
void ListPrint(ListNode* phead);
void ListPushBack(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x); // pos位置之前插入
void ListErase(ListNode* pos); // 删除pos位置

void ListDestroy(ListNode* phead);