#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* deleteDuplication(struct ListNode* pHead)
{
	struct ListNode* prev = NULL;
	struct ListNode* cur = pHead;
	struct ListNode* next = pHead->next;
	while (next)
	{
		if (cur->val == next->val)
		{
			while (next && cur->val == next->val) //cur指向的值与next指向的值相同，则next一直加加直到不相同
			{
				next = next->next;
			}
			while (cur != next)         //删除cur到next之间相同的节点
			{
				struct ListNode* del = cur;
				cur = cur->next;
				free(del);
			}
			if (prev == NULL)        //都为相同的节点
			{
				pHead = cur;
			}
			else                   //prev指向下一个节点的下一个节点
			{
				prev = prev->next;
			}
		}
		else
		{
			prev = cur;
			cur = next;
			next = next->next;
		}
	}
	return pHead;
}
int main()
{
	return 0;
}