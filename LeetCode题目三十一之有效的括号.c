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
	pst->a = pst->capacity = 0;
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

//1.�����Ž�ջ��������������ĵ�������ƥ��
bool isValid(char *s)
{
	struct Stack st;
	StackInit(&st);
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st,*s);
			s++;
		}
		else
		{
			//Ϊ�գ�û�н�ջ��û��������
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}
			char top = StackTop(&st);
			if ((top == '('&&*s != ')') || (top == '{'&&*s != '}') || (top == '['&&*s != ']'))
			{
				StackDestroy(&st);
				return false;
			}
			else
			{
				StackPop(&st);
				s++;
			}
		}
	}
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}
int main()
{
	return 0;
}