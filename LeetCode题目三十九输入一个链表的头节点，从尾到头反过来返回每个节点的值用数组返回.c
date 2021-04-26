#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
int* reversePrint(struct ListNode* head, int* returnSize)
{
	int total = 0;
	int* src = (int*)malloc(sizeof(int)* 10000);
	struct ListNode* cur = head;
	while (cur)
	{
		struct ListNode* next = cur->next;
		src[total] = cur->val;
		total++;
		cur = next;
	}
	int i = 0;
	for (i = 0; i < total / 2; i++)
	{
		int tmp = src[i];
		src[i] = src[total - 1 - i];
		src[total - 1 - i] = src[i];
	}
	*returnSize = total;
	return src;
}
int main()
{
	return 0;
}