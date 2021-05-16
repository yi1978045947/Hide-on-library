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
			while (next && cur->val == next->val) //curָ���ֵ��nextָ���ֵ��ͬ����nextһֱ�Ӽ�ֱ������ͬ
			{
				next = next->next;
			}
			while (cur != next)         //ɾ��cur��next֮����ͬ�Ľڵ�
			{
				struct ListNode* del = cur;
				cur = cur->next;
				free(del);
			}
			if (prev == NULL)        //��Ϊ��ͬ�Ľڵ�
			{
				pHead = cur;
			}
			else                   //prevָ����һ���ڵ����һ���ڵ�
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