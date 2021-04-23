#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
//1.��ʼ����
//2.��ֹ����
//3.��������
struct ListNode* insertionSortList(struct ListNode* head)
{
	//1.��ʼ����
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* sortHead = head;
	struct ListNode* cur = head->next;
	sortHead->next = NULL;
	//2.��ֹ����
	while (cur)
	{
	//3.��������
		struct ListNode* next = cur->next;
		struct ListNode* p = NULL, *c = sortHead;
		while (c)  //�м����
		{
			if (cur->val < c->val)
			{
				break;
			}
			else
			{
				p = c;
				c = c->next;
			}
		}
		if (p == NULL) //ͷ��
		{
			cur->next = c;
			sortHead = cur;
		}
		else          //β��
		{
			p->next = cur;
			cur->next = c;
		}
		cur = next;
	}
	return sortHead;
}