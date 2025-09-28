#include "seqlist.h"

void SLTest1()
{
	SL sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	//SeqListPopback(&sl);

	SeqListPushFront(&sl, 0);
	SeqListPushFront(&sl, -1);
	SeqListPushFront(&sl, -2);

	/*SeqListPopFront(&sl);
	SeqListPopFront(&sl);*/

	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}


void SLTest2()
{
	SL sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);

	/*int ret = SeqListFind(&sl, 2);
	printf("%d\n", ret);*/
	SeqListPosInsert(&sl, 3, 4);
	SeqListPosInsert(&sl, 3, 5);
	//SeqListPosErase(&sl, 0);
	//SeqListPosErase(&sl, 0);
	SeqListPrint(&sl);
	/*printf("\n");
	printf("%d\n", sl.capacity);*/

	SeqListDestroy(&sl);
}
int main()
{
	SLTest1();
	//SLTest2();
	return 0;
}