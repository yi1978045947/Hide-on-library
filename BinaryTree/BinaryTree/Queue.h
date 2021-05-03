#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
struct BinaryTreeNode;        //ǰ������
typedef struct BinaryTreeNode* QDataType;
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