#define _CRT_SECURE_NO_WARNINGS   1
#include"SeqList.h"

int main()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPrint(&s);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListDestroy(&s);
	return 0;
}