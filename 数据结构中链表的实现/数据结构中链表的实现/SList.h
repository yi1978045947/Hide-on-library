#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;          //������
	struct SListNode* next;   //ָ����
}SLTNode;

void  SListPrint(SLTNode* plist);                                        //��ӡ����
void SListPushBack(SLTNode** pplist, SLTDateType num);                   //β����������
void SListPushFront(SLTNode** pplist, SLTDateType num);                  //ͷ����������
void SListPopBack(SLTNode** pplist);                                     //β��ɾ������
void SListPopFront(SLTNode** pplist);                                    //ͷ��ɾ������
SLTNode* SListFindKey(SLTNode* plist,SLTDateType num);                   //��������
void SListInsertAfter(SLTNode* pos, SLTDateType num);                    //��posλ��֮�����
void SListInsertBefore(SLTNode** pplist, SLTNode* pos, SLTDateType num); //��posλ��֮ǰ����
void SListEarseAfter(SLTNode* pos);                                      //��pos����ɾ������
