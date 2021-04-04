#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SeqDataType;  //把int类型重命名为SeqDataType

typedef struct SeqList
{
	SeqDataType* arr;  //动态开辟的数组
	int size;       //有效数据的个数
	int capacity;  //容量
}SeqList;

void SeqListInit(SeqList* pq);                                          //初始化顺序表
void SeqListPushBack(SeqList* pq, SeqDataType num);                     //尾上插入数据]
void SeqListPushFront(SeqList* pq, SeqDataType num);                    //头上插入数据
void SeqListPopBack(SeqList* pq);                                       //尾上删除数据
void SeqListPopFront(SeqList* pq);                                      //头上删除数据
int  SeqListSearchData(SeqList* pq, SeqDataType num);                   //查找数据
void SeqListInsert(SeqList* pq, SeqDataType num, SeqDataType pos);      //任意位置插入数据
void SeqListErase(SeqList* pq, SeqDataType pos);                        //任意位置删除数据
void SeqListModify(SeqList* pq, SeqDataType pos,SeqDataType num);       //修改数据
void ShowSeqList(SeqList* pq);                                          //显示顺序表
void SeqListDestory(SeqList* pq);                                       //销毁顺序表