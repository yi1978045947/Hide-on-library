#define _CRT_SECURE_NO_WARNINGS   1
#include"Queue.h"
void QueueInit(struct Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void QueueDestroy(struct Queue* pq)
{
	assert(pq);
	struct QueueNode* cur = pq->head;
	while (cur)
	{
		struct QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
void QueuePush(struct Queue* pq, QDataType x)   //队尾入数据
{
	assert(pq);
	struct QueueNode* newnode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	if (newnode == NULL)
	{
		printf("开辟失败!\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)   //无节点
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(struct Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (pq->head->next==NULL)  //只有一个节点
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		struct QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}
QDataType QueueFront(struct Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
QDataType QueueBack(struct Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}
bool QueueEmpty(struct Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
int QueueSize(struct Queue* pq)
{
	int size = 0;
	assert(pq);
	struct QueueNode* cur = pq->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}