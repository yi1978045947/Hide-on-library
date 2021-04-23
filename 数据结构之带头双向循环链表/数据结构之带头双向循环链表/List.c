#define _CRT_SECURE_NO_WARNINGS   1
#include"List.h"
struct ListNode* BuyListNode(LTDataType x)
{
	struct ListNode* Node = (struct ListNode*)malloc(sizeof(struct ListNode));
	Node->next = NULL;
	Node->prev = NULL;
	Node->data = x;
	return Node;
}
struct ListNode* ListInit()
{
	struct ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void  ListPushBack(struct ListNode* phead, LTDataType x)
{
	assert(phead);
	struct ListNode* tail = phead->prev;
	struct ListNode* newnode = BuyListNode(x);
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}
void ListPushFront(struct ListNode* phead, LTDataType x)
{
	assert(phead);
	struct ListNode* newnode = BuyListNode(x);
	struct ListNode* first = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
}
void ListPopBack(struct ListNode* phead)
{
	assert(phead);
	assert(phead != phead->next);
	struct ListNode* tail = phead->prev;
	struct ListNode* second = tail->prev;
	free(tail);
	tail = NULL;
	second->next = phead;
	phead->prev = second;
}
void ListPopFront(struct ListNode* phead)
{
	assert(phead);
	assert(phead != phead->next);
	struct ListNode* first = phead->next;
	struct ListNode* firstNext = first->next;
	free(first);
	first = NULL;
	phead->next = firstNext;
	first->prev = phead;
}
struct ListNode* ListFind(struct ListNode* phead, LTDataType x)
{
	assert(phead);
	struct ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListInsert(struct ListNode* pos, LTDataType x)
{
	assert(pos);
	struct ListNode* newnode = BuyListNode(x);
	struct ListNode* prev = pos->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
void ListEarse(struct ListNode* pos)
{
	assert(pos);
	struct ListNode* prev = pos->prev;
	struct ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}
int ListEmpty(struct ListNode* phead)
{
	assert(phead);
	return phead->next == phead ? 1 : 0;
}
int ListSize(struct ListNode* phead)
{
	assert(phead);
	int size = 0;
	struct ListNode* cur = phead->next;
	while (cur != phead)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
void ListDestory(struct ListNode* phead)
{
	assert(phead);
	struct ListNode* cur = phead->next;
	while (cur != phead)
	{
		struct ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}
void ListPrint(struct ListNode* phead)
{
	assert(phead);
	struct ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}