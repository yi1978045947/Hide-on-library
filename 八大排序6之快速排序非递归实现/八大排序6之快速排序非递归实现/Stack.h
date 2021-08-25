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