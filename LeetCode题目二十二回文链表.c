#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdbool.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* fast = head, *slow = head;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
struct ListNode* reverse(struct ListNode* head)
{
	struct ListNode* cur = head;
	struct ListNode* newhead = NULL;
	while (cur)
	{
		struct ListNode* next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}
bool isPalindrome(struct ListNode* head)
{
	struct ListNode* mid = middleNode(head);
	struct ListNode* rhead = reverse(mid);
	while (head&&rhead)
	{
		if (head->val != rhead->val)
		{
			return false;
		}
		else
		{
			head = head->next;
			rhead = rhead->next;
		}
	}
	return true;
}