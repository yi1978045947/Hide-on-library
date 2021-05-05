#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int STDataType;
struct Stack       //动态增长的栈
{
	STDataType* a;
	int top;        //栈顶
	int capacity;   //容量
};

void StackInit(struct Stack* pst);                        //初始化栈
void StackDestroy(struct Stack* pst);                     //销毁栈

void StackPush(struct Stack* pst, STDataType x);          //入栈
void StackPop(struct Stack* pst);                         //出栈

STDataType StackTop(struct Stack* pst);                   //获取栈顶数据

bool StackEmpty(struct Stack* pst);                       //检测栈是否为空
STDataType StackSize(struct Stack* pst);                  //获取栈中有效数据个数
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
	if (pst->top == pst->capacity)   //容量不够则增加容量
	{
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType)*pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("开辟空间失败!\n");
			exit(-1);  //0是正常退出，-1是异常退出
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
	return pst->a[pst->top - 1];  //top减一就是栈顶数据
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
	if (StackEmpty(&obj->popST))  //只要popST栈为空，就把pushST栈的内容取出来倒过去
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));//取pushST栈顶的数据导入popST的栈里
			StackPop(&obj->pushST);
		}
	}
	int top = StackTop(&obj->popST); //获取popST的数据
	StackPop(&obj->popST);
	return top;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
	if (StackEmpty(&obj->popST))  //只要popST栈为空，就把pushST栈的内容取出来倒过去
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));//pushST栈顶的数据
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