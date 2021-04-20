#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode *detectCycle(struct ListNode *head)
{
	struct ListNode* fast = head, *slow = head;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			struct ListNode* meet = fast;
			while (meet != head)
			{
				meet = meet->next;
				head = head->next;
			}
			return meet;
		}
	}
	return NULL;
}