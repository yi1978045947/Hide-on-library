#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* partition(struct ListNode* pHead, int x)
{
	struct ListNode* lessTail = NULL, *lessHead = NULL, *greaterTail = NULL, *greaterHead = NULL;
	lessTail = lessHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterTail = greaterHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	lessTail->next = NULL;
	greaterTail->next = NULL;
	struct ListNode* cur = pHead;
	while (cur)
	{
		if (cur->val < x)
		{
			lessTail->next = cur;
			lessTail = lessTail->next;
		}
		else
		{
			greaterTail->next = cur;
			greaterTail = greaterTail->next;
		}
		cur = cur->next;
	}
	//把大于x值的链表连接到小于x值的链表后面
	lessTail->next = greaterTail->next;
	greaterTail->next = NULL;
	pHead = lessHead->next;
	free(lessHead);
	free(greaterHead);
	return pHead;
}