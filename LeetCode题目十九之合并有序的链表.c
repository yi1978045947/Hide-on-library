#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	//�ж��ĸ�����Ϊ�գ�Ȼ�󷵻���һ������
	if (l1==NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	struct ListNode* head = NULL, *tail = NULL;
	//��ȥ����������С����Ϊ��һ�����
	if (l1->next < l2->next)
	{
		head = tail = l1;
		l1 = l1->next;
	}
	else
	{
		head = tail = l2;
		l2 = l2->next;
	}
	//ȥ���������������Ƚ�β�嵽��һ��������
	while (l1&&l2)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	//�ж�˭���н����Һ��滹�н�㣬ֱ�����ӵ�β�����ȥ
	if (l1)
	{
		tail->next = l1;
	}
	if (l2)
	{
		tail->next = l2;
	}
	return head;
}