#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int STDataType;
struct Stack       //��̬������ջ
{
	STDataType* a;
	int top;        //ջ��
	int capacity;   //����
};

void StackInit(struct Stack* pst);                        //��ʼ��ջ
void StackDestroy(struct Stack* pst);                     //����ջ

void StackPush(struct Stack* pst, STDataType x);          //��ջ
void StackPop(struct Stack* pst);                         //��ջ

STDataType StackTop(struct Stack* pst);                   //��ȡջ������

bool StackEmpty(struct Stack* pst);                       //���ջ�Ƿ�Ϊ��
STDataType StackSize(struct Stack* pst);                  //��ȡջ����Ч���ݸ���
void StackInit(struct Stack* pst)
{
	assert(pst);
	//pst->a = NULL;
	//pst->top = 0;
	//pst->capacity = 0;
	pst->a = (STDataType*)malloc(sizeof(STDataType)* 4);
	pst->top = 0;
	pst->capacity = 4;
}
void StackDestroy(struct Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}
void StackPush(struct Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)   //������������������
	{
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType)*pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("���ٿռ�ʧ��!\n");
			exit(-1);  //0�������˳���-1���쳣�˳�
		}
		pst->a = tmp;
		pst->capacity = pst->capacity * 2;
	}
	pst->a[pst->top] = x;
	pst->top++;
}
void StackPop(struct Stack* pst)
{
	assert(pst);
	assert(!(StackEmpty(pst)));
	pst->top--;
}
STDataType StackTop(struct Stack* pst)
{
	assert(pst);
	assert(!(StackEmpty(pst)));
	return pst->a[pst->top - 1];  //top��һ����ջ������
}
bool StackEmpty(struct Stack* pst)
{
	assert(pst);
	return pst->top == 0;
}
STDataType StackSize(struct Stack* pst)
{
	return pst->top;
}

typedef struct
{
	struct Stack pushST;
	struct Stack popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate()
{
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->pushST);
	StackInit(&q->popST);
	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
	if (StackEmpty(&obj->popST))  //ֻҪpopSTջΪ�գ��Ͱ�pushSTջ������ȡ��������ȥ
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));//ȡpushSTջ�������ݵ���popST��ջ��
			StackPop(&obj->pushST);
		}
	}
	int top = StackTop(&obj->popST); //��ȡpopST������
	StackPop(&obj->popST);
	return top;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
	if (StackEmpty(&obj->popST))  //ֻҪpopSTջΪ�գ��Ͱ�pushSTջ������ȡ��������ȥ
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));//pushSTջ��������
			StackPop(&obj->pushST);
		}
	}
	return StackTop(&obj->popST);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
	return (StackEmpty(&obj->pushST) && StackEmpty(&obj->popST));
}

void myQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);
	free(obj);
}

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/
int main()
{
	return 0;
}