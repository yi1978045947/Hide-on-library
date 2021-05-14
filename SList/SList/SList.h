#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

struct ListNode
{
	int val;
	struct ListNode* next;
};

void SListInit(struct ListNode** pplist);
void SListDestroy(struct ListNode** pplist);

int SListSize(struct ListNode* plist);
struct ListNode* SListFind(struct ListNode* plist, SLDataType x);
void SListPrint(struct ListNode* plist);

void SListPushBack(struct ListNode** pplist, SLDataType x);
void SListPushFront(struct ListNode** pplist, SLDataType x);
void SListPopBack(struct ListNode** pplist);
void SListPopFront(struct ListNode** pplist);

void SListInsertAfter(struct ListNode* pos, SLDataType x);

void SListEraseAfter(struct ListNode* pos);