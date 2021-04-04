#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SeqDataType;  //��int����������ΪSeqDataType

typedef struct SeqList
{
	SeqDataType* arr;  //��̬���ٵ�����
	int size;       //��Ч���ݵĸ���
	int capacity;  //����
}SeqList;

void SeqListInit(SeqList* pq);                                          //��ʼ��˳���
void SeqListPushBack(SeqList* pq, SeqDataType num);                     //β�ϲ�������]
void SeqListPushFront(SeqList* pq, SeqDataType num);                    //ͷ�ϲ�������
void SeqListPopBack(SeqList* pq);                                       //β��ɾ������
void SeqListPopFront(SeqList* pq);                                      //ͷ��ɾ������
int  SeqListSearchData(SeqList* pq, SeqDataType num);                   //��������
void SeqListInsert(SeqList* pq, SeqDataType num, SeqDataType pos);      //����λ�ò�������
void SeqListErase(SeqList* pq, SeqDataType pos);                        //����λ��ɾ������
void SeqListModify(SeqList* pq, SeqDataType pos,SeqDataType num);       //�޸�����
void ShowSeqList(SeqList* pq);                                          //��ʾ˳���
void SeqListDestory(SeqList* pq);                                       //����˳���