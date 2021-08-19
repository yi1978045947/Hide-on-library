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

// ����+����ͷ+��ѭ��
void SListPrint(SLTNode* plist);
void SListPushBack(SLTNode** pplist, SLTDataType x);
void SListPushFront(SLTNode** pplist, SLTDataType x);

void SListPopBack(SLTNode** pplist);
void SListPopFront(SLTNode** pplist);

// ���������
SLTNode* SListFind(SLTNode* plist, SLTDataType x);

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SLTNode* pos, SLTDataType x);

// ��������posλ��֮ǰ����  (���鷳���ʺ�)
void SListInsertBefore(SLTNode** plist, SLTNode* pos, SLTDataType x);

void SListEraseAfter(SLTNode* pos);

void SListEraseCur(SLTNode** plist, SLTNode* pos);


