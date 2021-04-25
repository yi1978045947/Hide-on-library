#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
typedef int QDataType;
struct QueueNode             //队列结构,用链表来表示
{
	struct QueueNode* next;
	QDataType data;
};
struct Queue                //队列头尾指针
{
	struct QueueNode* head;
	struct QueueNode* tail;
};

void QueueInit(struct Queue* pq);                    //初始化队列
void QueueDestroy(struct Queue* pq);                 //销毁队列

void QueuePush(struct Queue* pq, QDataType x);       //队尾入数据
void QueuePop(struct Queue* pq);                     //队头出数据

QDataType QueueFront(struct Queue* pq);              //取队头数据
QDataType QueueBack(struct Queue* pq);               //取队尾数据

bool QueueEmpty(struct Queue* pq);                   //判断队列是否为空
int QueueSize(struct Queue* pq);                     //求队列长度

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
	if (pq->head->next == NULL)  //只有一个节点
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
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));  //在堆去开辟一块空间，用指针pst指向这块空间
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);
	return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x)  //录入数据
{
	if (!QueueEmpty(&obj->q1)) //q1不为空
	{
		QueuePush(&obj->q1, x);  //q1录入数据
	}
	else
	{
		QueuePush(&obj->q2, x);  //q2录入数据
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
	while (QueueSize(pNoEmpty)>1) //取出数据来插过去，直到最后一个
	{
		QueuePush(pEmpty, QueueFront(pNoEmpty));
		QueuePop(pNoEmpty);
	}
	int front = QueueFront(pNoEmpty);
	QueuePop(pNoEmpty);  //注意
	return front;
}

/** Get the top element. */
int myStackTop(MyStack* obj) //获取栈顶数据
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
bool myStackEmpty(MyStack* obj) //判断栈是否为空
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