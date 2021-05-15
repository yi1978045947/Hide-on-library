#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int val;
	struct Node *next;
	struct Node *random;
};

struct Node* copyRandomList(struct Node* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	//1.�����ڵ����ԭ�ڵ�ĺ���
	struct Node* cur = head;
	while (cur)
	{
		struct Node* next = cur->next;
		struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
		copy->val = cur->val;
		cur->next = copy;
		copy->next = next;
		cur = next;
	}
	//2.����copy�ڵ��random
	cur = head;
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
	//3.�ѿ����Ľڵ�ȡ�������ӵ�һ�𣬻ָ�ԭ����
	cur = head;
	struct Node* copyHead, *copyTail;
	copyHead = copyTail = (struct Node*)malloc(sizeof(struct Node));
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;
		//β��
		copyTail->next = copy;
		copyTail = copyTail->next;

		cur->next = next;
		cur = next;
	}
	struct Node* guard = copyHead;
	copyHead = copyHead->next;
	free(guard);
	return copyHead;
}
int main()
{
	return 0;
}