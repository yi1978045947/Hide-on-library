#pragma once
#include "SList.h"

void SListPrint(SLTNode* plist)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;

	return node;
}

void SListPushBack(SLTNode** pplist, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);

	// 1.��
	// 2.�ǿ�
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		// ��β
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pplist, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void SListPopBack(SLTNode** pplist)
{
	// 1��û�нڵ�
	// 2��һ���ڵ�
	// 3������ڵ�
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
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