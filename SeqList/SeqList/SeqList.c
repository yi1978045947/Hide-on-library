#define _CRT_SECURE_NO_WARNINGS   1
#include"SeqList.h"
void CheckCapacity(SeqList* pq)
{
	assert(pq);
	if (pq->size == pq->capacity)
	{
		SQLDataType newcapacity = pq->capacity == 0 ? 8 : pq->capacity * 2;
		SQLDataType* newarr = (SQLDataType*)realloc(pq->arr, sizeof(SQLDataType)*newcapacity);
		pq->capacity = newcapacity;
		pq->arr = newarr;
		if (newarr == NULL)
		{
			printf("Realloc Fail!\n");
		}
	}
}
void SeqListPrint(SeqList* pq)
{
	assert(pq);
	int i = 0;
	for (i = 0; i < pq->size; i++)
	{
		printf("%d ", pq->arr[i]);
	}
	printf("\n");
}

void SeqListInit(SeqList* pq)
{
	assert(pq);
	pq->arr = NULL;
	pq->capacity = pq->size = 0;
}
void SeqListDestroy(SeqList* pq)
{
	assert(pq);
	free(pq->arr);
	pq->arr = NULL;
	pq->capacity = pq->size = 0;
}

int SeqListSize(SeqList* pq)
{
	assert(pq);
	return pq->size;
}
int SeqListCapacity(SeqList* pq)
{
	assert(pq);
	return pq->capacity;
}
bool SeqListEmpty(SeqList* pq)
{
	return pq->size == 0;
}

void SeqListPushBack(SeqList* pq, SQLDataType x)
{
	assert(pq);
	CheckCapacity(pq);
	pq->arr[pq->size] = x;
	pq->size++;
}
void SeqListPopBack(SeqList* pq)
{
	assert(pq);
	assert(!(SeqListEmpty(pq)));
	pq->size--;
}

void SeqListPushFront(SeqList* pq, SQLDataType x)
{
	assert(pq);
	CheckCapacity(pq);
	SQLDataType end = pq->size - 1;
	while (end >= 0)
	{
		pq->arr[end + 1] = pq->arr[end];
		end--;
	}
	pq->arr[0] = x;
	pq->size++;
}
void SeqListPopFront(SeqList* pq)
{
	assert(pq);
	assert(!(SeqListEmpty(pq)));
	SQLDataType begin = 0;
	while (begin < pq->size - 1)
	{
		pq->arr[begin] = pq->arr[begin + 1];
		begin++;
	}
	pq->size--;
}

int SeqListFind(SeqList* pq, SQLDataType x)
{
	assert(pq);
	int i = 0;
	for (i = 0; i < pq->size; i++)
	{
		if (pq->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListModify(SeqList* pq, int pos, SQLDataType x)
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);
	pq->arr[pos] = x;
}

void SeqListInsert(SeqList* pq, int pos, SQLDataType x)
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size - 1);
	CheckCapacity(pq);
	SQLDataType end = pq->size - 1;
	while (end >= pos)
	{
		pq->arr[end + 1] = pq->arr[end + 1];
		end--;
	}
	pq->arr[pos] = x;
	pq->size++;
}
void SeqListEarse(SeqList* pq, int pos)
{
	assert(pos);
	assert(!(SeqListEmpty(pq)));
	assert(pos >= 0 && pos < pq->size);
	int begin = pos;
	while (pos <= pq->size - 1)
	{
		pq->arr[begin] = pq->arr[begin + 1];
		begin++;
	}
	pq->size--;
}