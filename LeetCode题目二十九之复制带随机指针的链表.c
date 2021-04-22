#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};
struct Node* copyRandomList(struct Node* head)
{
	//1.����Դ�ڵ����ӵ��ڵ����
	struct Node* cur = head;
	while (cur)
	{
		struct Node* next = cur->next;
		struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
		copy->val = cur->val;
		cur->next = copy;
		cur = next;
	}
	//2.��������ڵ�random
	while (cur)
	{
		struct Node* copy = cur->next;
		if (cur->random == NULL)
		{
			copy->random = NULL;
		}
		else
		{
			copy->random = cur->random->next;
		}
		cur = copy->next;
	}
	//3.�����ڵ�ȡ�������ӵ�һ�𣬻ָ�ԭ����
	struct Node* copyhead, *copytail;
	copyhead = copytail = (struct Node*)malloc(sizeof(struct Node));
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;
		//β��
		copytail->next = copy;
		copytail = copytail->next;
		cur->next = cur;
		cur = next;
	}
	struct Node* guard = copyhead;
	copyhead = copyhead->next;
	free(guard);
	return copyhead;
}
int main()
{
	return 0;
}