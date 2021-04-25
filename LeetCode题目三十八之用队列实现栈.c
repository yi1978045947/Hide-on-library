#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
typedef int QDataType;
struct QueueNode             //���нṹ,����������ʾ
{
	struct QueueNode* next;
	QDataType data;
};
struct Queue                //����ͷβָ��
{
	struct QueueNode* head;
	struct QueueNode* tail;
};

void QueueInit(struct Queue* pq);                    //��ʼ������
void QueueDestroy(struct Queue* pq);                 //���ٶ���

void QueuePush(struct Queue* pq, QDataType x);       //��β������
void QueuePop(struct Queue* pq);                     //��ͷ������

QDataType QueueFront(struct Queue* pq);              //ȡ��ͷ����
QDataType QueueBack(struct Queue* pq);               //ȡ��β����

bool QueueEmpty(struct Queue* pq);                   //�ж϶����Ƿ�Ϊ��
int QueueSize(struct Queue* pq);                     //����г���

#define _CRT_SECURE_NO_WARNINGS   1
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
void QueuePush(struct Queue* pq, QDataType x)   //��β������
{
	assert(pq);
	struct QueueNode* newnode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	if (newnode == NULL)
	{
		printf("����ʧ��!\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)   //�޽ڵ�
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
	if (pq->head->next == NULL)  //ֻ��һ���ڵ�
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
typedef struct
{
	struct Queue q1;
	struct Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate()
{
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));  //�ڶ�ȥ����һ��ռ䣬��ָ��pstָ�����ռ�
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x)  //¼������
{
	if (!QueueEmpty(&obj->q1)) //q1��Ϊ��
	{
		QueuePush(&obj->q1, x);  //q1¼������
	}
	else
	{
		QueuePush(&obj->q2, x);  //q2¼������
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
	struct Queue* pEmpty = &obj->q1;
	struct Queue* pNoEmpty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		pNoEmpty = &obj->q1;
		pEmpty = &obj->q2;
	}
	while (QueueSize(pNoEmpty)>1) //ȡ�����������ȥ��ֱ�����һ��
	{
		QueuePush(pEmpty, QueueFront(pNoEmpty));
		QueuePop(pNoEmpty);
	}
	int front = QueueFront(pNoEmpty);
	QueuePop(pNoEmpty);  //ע��
	return front;
}

/** Get the top element. */
int myStackTop(MyStack* obj) //��ȡջ������
{
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) //�ж�ջ�Ƿ�Ϊ��
{
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

/**
* Your MyStack struct will be instantiated and called as such:
* MyStack* obj = myStackCreate();
* myStackPush(obj, x);

* int param_2 = myStackPop(obj);

* int param_3 = myStackTop(obj);

* bool param_4 = myStackEmpty(obj);

* myStackFree(obj);
*/
int main()
{
	return 0;
}