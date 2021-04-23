#define _CRT_SECURE_NO_WARNINGS   1
#include"Stack.h"
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
		STDataType* tmp = (STDataType*)realloc(pst->a,sizeof(STDataType)*pst->capacity * 2);
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
