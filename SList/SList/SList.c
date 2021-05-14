#define _CRT_SECURE_NO_WARNINGS   1
#include"SList.h"

struct ListNode* BuyNode(SLDataType x)
{
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}


void SListInit(struct ListNode** pplist)
{
	*pplist = NULL;
}
void SListDestroy(struct ListNode** pplist)
{
	assert(pplist);
	struct ListNode* cur = *pplist;
	while (cur)
	{
		struct ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
}

int SListSize(struct ListNode* plist)
{
	int size = 0;
	assert(plist);
	struct ListNode* cur = plist;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	return size;
}
struct ListNode* SListFind(struct ListNode* plist, SLDataType x)
{
	assert(plist);
	struct ListNode* cur = plist;
	while (cur)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void SListPrint(struct ListNode* plist)
{
	assert(plist);
	struct ListNode* cur = plist;
	while (cur)
	{
		printf("%d-->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(struct ListNode** pplist, SLDataType x)
{
	assert(pplist);
	struct ListNode* newnode = BuyNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		struct ListNode* cur = *pplist;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}
void SListPushFront(struct ListNode** pplist, SLDataType x)
{
	assert(pplist);
	struct ListNode* newnode = BuyNode(x);
	(*pplist)->next = newnode;
	newnode = *pplist;
}
void SListPopBack(struct ListNode** pplist)
{
	assert(pplist);
	struct ListNode* tail = *pplist;
	struct ListNode* prev = NULL;
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
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}
void SListPopFront(struct ListNode** pplist)
{
	assert(pplist);
	struct ListNode* next = (*pplist)->next;
	free(*pplist);
	*pplist = next;
}
void SListInsertAfter(struct ListNode* pos, SLDataType x)
{
	assert(pos);
	struct ListNode* newnode = BuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEraseAfter(struct ListNode* pos)
{
	assert(pos);
	assert(pos->next);
	struct ListNode* next = pos->next;
	pos->next = next->next;
	free(pos->next);
}