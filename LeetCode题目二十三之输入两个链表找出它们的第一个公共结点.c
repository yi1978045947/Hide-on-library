#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<math.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
//1.�����������ĳ���
//2.�Ƚ���������˭����
//3.���������������ĳ���
//4.���������������ĳ��ȣ�Ȼ��������һ������
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	struct ListNode* curA = headA, *curB = headB;
	int lenA = 0;
	int lenB = 0;
	while (curA->next)  //���curA�ǿ�������������
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