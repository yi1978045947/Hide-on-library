#define _CRT_SECURE_NO_WARNINGS   1
#include"SeqList.h"
void SeqListInit(SeqList* pq)
{
	assert(pq);
	pq->arr = NULL;
	pq->size = 0;
	pq->capacity = 0;
}
void SeqListCheckCapacity(SeqList* pq)       //增加容量
{
	if (pq->size == pq->capacity)
	{
		SeqDataType newcapacity = pq->capacity == 0 ? 8 : pq->capacity * 2;  //pq->capacity起始为空
		SeqDataType* newarr = realloc(pq->arr, sizeof(SeqDataType)*newcapacity);
		pq->capacity = newcapacity;
		pq->arr = newarr;
		if (newarr == NULL)
		{
			printf("增加容量失败!\n");
			exit(1);
		}
	}
}
void SeqListPushBack(SeqList* pq, int num)
{
	assert(pq);
	SeqListCheckCapacity(pq);
	pq->arr[pq->size] = num;
	pq->size++;
}
void SeqListPushFront(SeqList* pq, SeqDataType num)
{
	assert(pq);
	SeqListCheckCapacity(pq);
	SeqDataType end = pq->size - 1;
	while (end >= 0)
	{
		pq->arr[end + 1] = pq->arr[end ];
		end--;
	}
	pq->arr[0] = num;
	pq->size++;
}
void SeqListPopBack(SeqList* pq)
{
	assert(pq);
	assert(pq->size>0);
	pq->size--;
}
void SeqListPopFront(SeqList* pq)
{
	assert(pq);
	assert(pq->size>0);
	SeqDataType front = 0;
	while (front<pq->size-1)
	{
		pq->arr[front] = pq->arr[front + 1];
		front++;
	}
	pq->size--;
}
int SeqListSearchData(SeqList* pq, SeqDataType num)
{
	assert(pq);
	int i = 0;
	for (i = 0; i < pq->size; i++)
	{
		if (pq->arr[i] == num)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* pq, SeqDataType num, SeqDataType pos)
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);
	SeqListCheckCapacity(pq);
	SeqDataType end = pq->size - 1;
	while (end >= pos)
	{
		pq->arr[end + 1] = pq->arr[end];
		end--;
	}
	pq->arr[pos] = num;
	pq->size++;
}
void SeqListErase(SeqList* pq,SeqDataType pos)
{
	assert(pq);
	assert(pq->size > 0);
	assert(pos >= 0 && pos < pq->size);
	SeqDataType begin = pos;
	while (begin <= pq->size - 1)
	{
		pq->arr[ begin ] = pq->arr[ begin+1 ];
		begin++;
	}
	pq->size--;
}
void SeqListModify(SeqList* pq, SeqDataType pos, SeqDataType num)
{
	assert(pq);
	assert(pos >= 0 && pos < pq->size);
	pq->arr[pos] = num;
}
void ShowSeqList(SeqList* pq)
{
	int i = 0;
	for (i = 0; i < pq->size; i++)
	{
		printf("%d ",pq->arr[i]);
	}
	printf("\n");
}
void SeqListDestory(SeqList* pq)
{
	assert(pq);
	free(pq->arr);
	pq->arr = NULL;
	pq->size = 0;
	pq->capacity = 0;
}