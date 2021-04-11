#define _CRT_SECURE_NO_WARNINGS   1
#include "SList.h"
void SListPrint(SLTNode* plist)
{
	assert(plist);
	SLTNode* cur = plist;
	while (cur !=NULL)
	{
		printf("%d--> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
SLTNode* BuyListNode(SLTDateType num)                     //����һ�����
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	assert(node);
	node->data = num;
	node->next = NULL;
	return node;
}
void SListPushBack(SLTNode** pplist, SLTDateType num)     //β����������,��ı��һ����㣬���Դ�����ָ��
{
	assert(pplist);
	SLTNode* newnode = BuyListNode(num);                  //����һ���½��
	if (*pplist == NULL)                                 //���ǵ�ǰһ����㶼û�����
	{
		*pplist = newnode;
	}
	else
	{
		SLTNode* tail = *pplist;
		while (tail->next != NULL)  //�����ҵ�β���
		{
			tail = tail->next;
		}
		tail->next = newnode;  //���½��ĵ�ַ��ǰһ������ָ��
	}
}
void SListPushFront(SLTNode** pplist, SLTDateType num)
{
	assert(pplist);
	SLTNode* newnode = BuyListNode(num);
	newnode->next = *pplist;
	*pplist = newnode;
}
void SListPopBack(SLTNode** pplist)
{
	//1.û�н��
	//2.1�����
	//3.������
	if (pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(pplist);
		*pplist = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}
void SListPopFront(SLTNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = (*pplist)->next;
		free(*pplist);
		*pplist = next;
	}
}
SLTNode* SListFindKey(SLTNode* plist, SLTDateType num)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		if (cur->data == num)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void SListInsertAfter(SLTNode* pos, SLTDateType num)
{
	assert(pos);
	SLTNode* newnode = BuyListNode(num);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SListInsertBefore(SLTNode** pplist, SLTNode* pos, SLTDateType num)
{
	assert(pos&&pplist);	
	SLTNode* newnode = BuyListNode(num);
	if (pos == *pplist)
	{
		newnode->next = pos;
		*pplist = newnode;
	}
	SLTNode* prev = NULL;
	SLTNode* cur = pplist;
	while (cur != pos)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = newnode;
	newnode->next = pos;
}
void SListEarseAfter(SLTNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SLTNode* cur = pos->next;
		pos->next = cur->next;
	}
}