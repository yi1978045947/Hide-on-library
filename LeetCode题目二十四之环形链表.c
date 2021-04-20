#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdbool.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
bool hasCycle(struct ListNode *head)
{
	struct ListNode* fast = head, *slow = head;
	while (fast&&fast->next)
	{
		slow = slow->next->next;
		fast = fast->next;
		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	return 0;
}