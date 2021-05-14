#define _CRT_SECURE_NO_WARNINGS   1

#include"SList.h"
int main()
{
	struct ListNode* head = NULL;
	SListInit(&head);
	SListPushBack(&head, 1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPrint(head);
	SListPopBack(&head);
	SListPrint(head);
	SListDestroy(&head);
	return 0;
}