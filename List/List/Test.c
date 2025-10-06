#include "List.h"

void TestList1()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//ListPopBack(plist);

	ListPrint(plist);

	ListNode* pos1 = ListFind(plist, 2);
	//printf("%p, %d\n", pos1, pos1->data);
	ListInsert(pos1, 6);
	ListPrint(plist);

	ListErase(pos1);
	ListPrint(plist);

	ListDestroy(plist);
	plist = NULL;
}

void TestList2()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);

	ListPopFront(plist);

	ListPrint(plist);
	ListDestroy(plist);
	plist = NULL;
}

int main()
{
	//TestList1();
	TestList2();
	return 0;
}