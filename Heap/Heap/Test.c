#include "Heap.h"

void HeapSort(int* arr, int n)
{
	//½¨¶Ñ
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, n, i);
	}

	//¶ÑÅÅÐò
	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}

void Test1()
{
	Heap hp;
	int a2[] = { 27,15,19,18,28,34,65,49,25,37 };
	HeapInit(&hp, a2, sizeof(a2) / sizeof(HPDataType));
	HeapPrint(&hp);
	HeapPush(&hp, 13);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);

	HeapDestroy(&hp);
}

int main()
{
	//int a1[] = { 27,15,19,18,28,34,65,49,25,37 };
	//HeapSort(a, sizeof(a) / sizeof(int));

	Test1();
	return 0;
}