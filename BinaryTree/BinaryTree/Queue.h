#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
struct BinaryTreeNode;        //前置声明
typedef struct BinaryTreeNode* QDataType;
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