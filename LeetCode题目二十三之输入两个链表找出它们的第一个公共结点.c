#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<math.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
//1.求出两个链表的长度
//2.比较两个链表谁更长
//3.求出两个链表的相差的长度
//4.长的链表先走相差的长度，然后两链表一起走完
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	struct ListNode* curA = headA, *curB = headB;
	int lenA = 0;
	int lenB = 0;
	while (curA->next)  //如果curA是空链表，则程序崩溃
	{
		lenA++;
		curA = curA->next;
	}
	while (curB->next)
	{
		lenB++;
		curB = curB->next;
	}
	if (curA != curB)
	{
		return NULL;
	}
	struct ListNode* longList = headA, *shortList = headB;
	if (lenB > lenA)
	{
		longList = headB;
		shortList = headA;
	}
	int gap = abs(lenA - lenB);
	while (gap--)
	{
		longList = longList->next;
	}
	while (longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}
	return longList;
}
int main()
{
	return 0;
}