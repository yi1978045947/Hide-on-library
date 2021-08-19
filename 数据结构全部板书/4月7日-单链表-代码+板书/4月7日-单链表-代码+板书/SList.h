#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

// 单向+不带头+不循环
void SListPrint(SLTNode* plist);
void SListPushBack(SLTNode** pplist, SLTDataType x);
void SListPushFront(SLTNode** pplist, SLTDataType x);

void SListPopBack(SLTNode** pplist);
void SListPopFront(SLTNode** pplist);

// 单链表查找
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// 单链表在pos位置之前插入  (很麻烦不适合)
void SListInsertBefore(SLTNode** plist, SLTNode* pos, SLTDataType x);

void SListEraseAfter(SLTNode* pos);

void SListEraseCur(SLTNode** plist, SLTNode* pos);


