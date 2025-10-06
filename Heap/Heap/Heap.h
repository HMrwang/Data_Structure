#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

void AdjustDown(HPDataType* arr, int n, int root);
void Swap(HPDataType* p1, HPDataType* p2);

void HeapInit(Heap* php, HPDataType* arr, int n);
void HeapDestroy(Heap* php);
void HeapPush(Heap* php, HPDataType x);
void HeapPop(Heap* php); //É¾¶¥¶ËÊý¾Ý
void HeapPrint(Heap* php);
HPDataType HeapTop(Heap* php);