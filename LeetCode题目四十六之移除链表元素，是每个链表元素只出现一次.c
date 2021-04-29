#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* cur = head;
	while (cur->next)
	{
		if (cur->val = cur->next->val)
		{
			cur->next = cur->next->next;
		}
		else
		{
			cur = cur->next;
		}
	}
	return head;
}
int main()
{
	return 0;
}