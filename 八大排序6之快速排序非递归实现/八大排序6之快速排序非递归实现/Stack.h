#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
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