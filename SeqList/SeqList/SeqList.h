#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int SQLDataType;

typedef struct SeqList
{
	SQLDataType* arr;
	int size;
	int capacity;
}SeqList;
void SeqListPrint(SeqList* pq);
void SeqListInit(SeqList* pq);
void SeqListDestroy(SeqList* pq);

int SeqListSize(SeqList* pq);
int SeqListCapacity(SeqList* pq);
bool SeqListEmpty(SeqList* pq);

void SeqListPushBack(SeqList* pq, SQLDataType x);
void SeqListPopBack(SeqList* pq);
void SeqListPushFront(SeqList* pq, SQLDataType x);
void SeqListPopFront(SeqList* pq);

int SeqListFind(SeqList* pq, SQLDataType x);
void SeqListModify(SeqList* pq, int pos, SQLDataType x);

void SeqListInsert(SeqList* pq, int pos, SQLDataType x);
void SeqListEarse(SeqList* pq, int pos);