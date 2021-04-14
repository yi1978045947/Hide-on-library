#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
//快慢指针方法
struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* fast = head, *slow = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}