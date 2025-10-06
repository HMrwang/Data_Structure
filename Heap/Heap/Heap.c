#include "Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//向下调整法（左右子树都是堆）
void AdjustDown(HPDataType* arr, int n, int root) //root为子树的根
{
	int parent = root;
	int child = parent * 2 + 1;
	
	while (child < n)
	{
		//找出小的子节点
		if (child + 1 < n && arr[child + 1] < arr[child])
		{
			child++;
		}

		//父子结点比较
		if (arr[child] < arr[parent]) //建小堆
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapInit(Heap* php, HPDataType* arr, int n) //n为数据个数
{
	//构建数组
	php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (php->a == NULL)
	{
		printf("Init Fail\n");
		exit(-1);
	}

	memcpy(php->a, arr, sizeof(HPDataType) * n);
	php->size = n;
	php->capacity = n;

	//构建堆
	//从下往上迭代
	int lastParent = (n - 1 - 1) / 2;
	for (int i = lastParent; i >= 0; i--)
	{
		AdjustDown(php->a, php->size, i);
	}

}

void HeapDestroy(Heap* php)
{
	assert(php);

	free(php->a);
	php->capacity = php->size = 0;
}

void AdjustUp(HPDataType* arr, int n, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* php, HPDataType x)
{
	assert(php);

	if (php->capacity == php->size)
	{
		php->capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * php->capacity);
		if (tmp == NULL)
		{
			printf("Push Fail\n");
			exit(-1);
		}
		php->a = tmp;
	}

	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size, php->size - 1);
}

void HeapPop(Heap* php)
{
	assert(php);
	assert(php->size > 0);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	AdjustDown(php->a, php->size, 0);
}

void HeapPrint(Heap* php)
{
	for (int i = 0; i < php->size - 1; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}