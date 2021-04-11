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
SLTNode* BuyListNode(SLTDateType num)                     //创建一个结点
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	assert(node);
	node->data = num;
	node->next = NULL;
	return node;
}
void SListPushBack(SLTNode** pplist, SLTDateType num)     //尾部插入数据,会改变第一个结点，所以传二级指针
{
	assert(pplist);
	SLTNode* newnode = BuyListNode(num);                  //创建一个新结点
	if (*pplist == NULL)                                 //考虑当前一个结点都没有情况
	{
		*pplist = newnode;
	}
	else
	{
		SLTNode* tail = *pplist;
		while (tail->next != NULL)  //遍历找到尾结点
		{
			tail = tail->next;
		}
		tail->next = newnode;  //把新结点的地址给前一个结点的指针
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
	//1.没有结点
	//2.1个结点
	//3.多个结点
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