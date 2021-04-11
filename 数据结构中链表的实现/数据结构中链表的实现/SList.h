#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;          //数据域
	struct SListNode* next;   //指针域
}SLTNode;

void  SListPrint(SLTNode* plist);                                        //打印链表
void SListPushBack(SLTNode** pplist, SLTDateType num);                   //尾部插入数据
void SListPushFront(SLTNode** pplist, SLTDateType num);                  //头部插入数据
void SListPopBack(SLTNode** pplist);                                     //尾部删除数据
void SListPopFront(SLTNode** pplist);                                    //头部删除数据
SLTNode* SListFindKey(SLTNode* plist,SLTDateType num);                   //查找数据
void SListInsertAfter(SLTNode* pos, SLTDateType num);                    //在pos位置之后插入
void SListInsertBefore(SLTNode** pplist, SLTNode* pos, SLTDateType num); //在pos位置之前插入
void SListEarseAfter(SLTNode* pos);                                      //在pos后面删除数据
