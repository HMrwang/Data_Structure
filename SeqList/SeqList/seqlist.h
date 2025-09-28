//��̬/��̬˳���  (��ʼ�������ݡ�ͷ��/ɾ��β��/ɾ�����ҡ�ָ���±��/ɾ��չʾ˳���

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#define N 50
typedef int SLDataType;

//��̬
//typedef struct SeqList
//{
//	SLDataType a[N];
//	int size;
//}SL;

//��̬
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

void SeqListPosInsert(SL* ps, int pos, SLDataType x);//pos�±����
void SeqListPosErase(SL* ps, int pos);//pos�±�ɾ��

void SeqListPrint(SL* ps);
