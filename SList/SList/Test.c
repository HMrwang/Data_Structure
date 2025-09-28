#include "SLList.h"

void Test1()
{
	SLLNode* plist = NULL;
	SLListPushBack(&plist, 1);
	SLListPushBack(&plist, 2);
	SLListPushBack(&plist, 3);
	SLListPushBack(&plist, 4);
	SLListPushFront(&plist, 1);
	SLListPushFront(&plist, 2);
	SLListPushFront(&plist, 3);
	SLListPushFront(&plist, 4);

	SLListPrint(plist);
}

void Test2()
{
	SLLNode* plist = NULL;
	SLListPushBack(&plist, 1);
	SLListPushBack(&plist, 2);
	SLListPushBack(&plist, 3);

	SLListPopFront(&plist);
	SLListPrint(plist);
	SLListPopFront(&plist);
	SLListPrint(plist);
	SLListPopFront(&plist);
	SLListPrint(plist);
	//SLListPopFront(&plist);

	/*SLListPopBack(&plist);
	SLListPopBack(&plist);
	SLListPopBack(&plist);*/

}

void Test3()
{
	SLLNode* plist = NULL;
	SLListPushBack(&plist, 1);
	SLListPushBack(&plist, 2);
	SLListPushBack(&plist, 3);
	SLListPushBack(&plist, 4);
	SLListPrint(plist);

	// 找链表中n个data为2的节点
	SLLNode* pos = SLListFind(plist, 2);
	int i = 1;
	while (pos)
	{
		printf("第%d个pos的节点为：%p->%d\n", i++, pos, pos->data);
		pos = SLListFind(pos->next, 2);
	}

	// 修改第一个data为2的节点为20
	pos = SLListFind(plist, 2);
	if (pos)
	{
		pos->data = 20;
	}
	SLListPrint(plist);
}

void Test4()
{
	SLLNode* plist = NULL;
	SLListPushBack(&plist, 1);
	SLListPushBack(&plist, 2);
	SLListPushBack(&plist, 3);
	SLListPushBack(&plist, 4);
	SLListPrint(plist);

	SLLNode* pos = SLListFind(plist, 1);
	SLListInsert(&plist, pos, 9);
	SLListPrint(plist);
}

void Test5()
{
	SLLNode* plist = NULL;
	SLListPushBack(&plist, 1);
	SLListPushBack(&plist, 2);
	SLListPushBack(&plist, 3);
	SLListPushBack(&plist, 4);
	SLListPrint(plist);

	SLLNode* pos = SLListFind(plist, 1);
	SLListErase(&plist, pos);
	SLListPrint(plist);

	SLListDestroy(&plist);
}

void Test6()
{
	SLLNode* plist = NULL;
	SLListPushBack(&plist, 1);
	SLListPushBack(&plist, 2);
	SLListPushBack(&plist, 3);
	SLListPushBack(&plist, 4);

	SLLNode* pos1 = SLListFind(plist, 1);
	SLListInsertAfter(&plist, pos1, 9);
	SLListPrint(plist);

	SLLNode* pos2 = SLListFind(plist, 2);
	SLListEraseAfter(&plist, pos2);
	SLListPrint(plist);
	
	SLListDestroy(&plist);
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	Test6();
	return 0;
}