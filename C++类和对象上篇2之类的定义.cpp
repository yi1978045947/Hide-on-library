#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
typedef int STDateType;
class Stack
{
public:
	//成员函数的声明
	void StackInit(int initSize = 4);
	void StackPush(STDateType x);

	//成员变量的声明
	STDateType* a;
	int size;
	int capacity;
};

//成员函数的定义
void Stack::StackInit(int initSize)
{
	a = (STDateType*)malloc(sizeof(STDateType)*initSize);
	size = 0;
	capacity = initSize;
}
void Stack::StackPush(STDateType x)	
{
	a[size] = x;
	size++;
}
int main()
{
	return 0;
}