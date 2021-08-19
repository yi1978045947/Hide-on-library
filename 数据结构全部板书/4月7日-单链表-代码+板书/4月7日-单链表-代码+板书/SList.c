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

// ���������
SLTNode* SListFind(SLTNode* plist, SLTDataType x)
{
	SLTNode* cur = plist;
	//while (cur != NULL)
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// ��������posλ��֮ǰ����
void SListInsertBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* newnode = BuySLTNode(x);

	if (pos == *pplist) // ͷ��
	{
		newnode->next = pos;
		*pplist = newnode;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* cur = *pplist;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}

		prev->next = newnode;
		newnode->next = pos;
	}
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = pos->next;
		pos->next = next->next;
		free(next);
	}
}