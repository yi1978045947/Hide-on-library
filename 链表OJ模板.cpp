#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<assert.h>
typedef struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}ListNode;
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x)
	{
		// write code here
		//两个哨兵节点greatHead，lessHead
		struct ListNode* lessHead = NULL, *lessTail = NULL;
		struct ListNode* greatHead = NULL, *greatTail = NULL;
		lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
		greatHead = greatTail = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* cur = pHead;
		while (cur)
		{
			if (cur->val < x)
			{
				lessTail->next = cur;
				lessTail = lessTail->next;
			}
			else
			{
				greatTail->next = cur;
				greatTail = greatTail->next;
			}
			cur = cur->next;
		}
		lessTail->next = greatHead->next;
		greatTail->next = NULL;
		pHead = lessHead->next;
		free(lessHead);
		free(greatHead);
		return  pHead;
	}
};
void SListPrint(struct ListNode* head)
{
	assert(head);
	struct ListNode* cur = head;
	while (cur)
	{
		printf("%d-->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}
int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n8 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 2;
	n2->val = 4;
	n3->val = 9;
	n4->val = 3;
	n5->val = 2;
	n6->val = 1;
	n7->val = 6;
	n8->val = 3;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = NULL;
	struct ListNode* head = Partition().partition(n1, 5);
	SListPrint(head);
	return 0;
}