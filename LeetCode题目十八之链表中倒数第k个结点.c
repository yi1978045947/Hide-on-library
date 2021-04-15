#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
	struct ListNode* fast = head, *slow = head;
	while (k--)
	{
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
	}
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}