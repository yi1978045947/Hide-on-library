#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
//1.起始条件
//2.终止条件
//3.迭代过程
struct ListNode* insertionSortList(struct ListNode* head)
{
	//1.起始条件
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* sortHead = head;
	struct ListNode* cur = head->next;
	sortHead->next = NULL;
	//2.终止条件
	while (cur)
	{
	//3.迭代条件
		struct ListNode* next = cur->next;
		struct ListNode* p = NULL, *c = sortHead;
		while (c)  //中间插入
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
		if (p == NULL) //头插
		{
			cur->next = c;
			sortHead = cur;
		}
		else          //尾插
		{
			p->next = cur;
			cur->next = c;
		}
		cur = next;
	}
	return sortHead;
}