#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLLDataType;

typedef struct SLListNode
{
	SLLDataType data;
	struct SLListNode* next;
}SLLNode;

void SLListPrint(SLLNode* phead);

void SLListPushBack(SLLNode** pphead, SLLDataType x);
void SLListPushFront(SLLNode** pphead, SLLDataType x);
void SLListPopBack(SLLNode** pphead);
void SLListPopFront(SLLNode** pphead);

SLLNode* SLListFind(SLLNode* phead, SLLDataType x);

void SLListInsert(SLLNode** pphead, SLLNode* pos, SLLDataType x);
void SLListInsertAfter(SLLNode* pos, SLLDataType x);
void SLListErase(SLLNode** pphead, SLLNode* pos);
void SLListEraseAfter(SLLNode* pos);

void SLListDestroy(SLLNode** pphead);
