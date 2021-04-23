#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
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
	pst->a = pst->capacity = 0;
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

//1.左括号进栈，右括号找最近的的左括号匹配
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
			//为空，没有进栈，没有左括号
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