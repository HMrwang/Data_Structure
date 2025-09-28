//静态/动态顺序表  (初始化、扩容、头插/删、尾插/删、查找、指定下标插/删、展示顺序表）

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#define N 50
typedef int SLDataType;

//静态
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size;
//}SL;

//动态
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;

void SeqListInit(SL* ps);
void SeqListDestroy(SL* ps);

void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPushFront(SL* ps, SLDataType x);

void SeqListPopFront(SL* ps);
void SeqListPopBack(SL* ps);

int SeqListFind(SL* ps, SLDataType x);

void SeqListPosInsert(SL* ps, int pos, SLDataType x);//pos下标插入
void SeqListPosErase(SL* ps, int pos);//pos下标删除

void SeqListPrint(SL* ps);
