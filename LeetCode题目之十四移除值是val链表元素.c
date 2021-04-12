#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* RemoveElements(struct ListNode* head, int val)
{
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;
	while (cur)
	{
		struct ListNode* next = cur->next;
		if (cur->next == val)
		{
			if (prev == NULL)  //第一个结点的值就是val
			{
				free(cur);
				head = next;
				cur = next;
			}
			else
			{
				prev->next = next;
				free(cur);
				cur = next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}