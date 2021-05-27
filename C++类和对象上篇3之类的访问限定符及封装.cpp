#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
typedef int STDateType;
//class定义的类不加访问限定符默认为私有变量，struct默认为公有变量
//成员变量(成员函数)想给别人访问定义为公有，不想给别人访问定义为私有
class Stack
{
public:
	//成员函数的声明
	void StackInit(int initSize = 4);
	void StackPush(STDateType x);

private:
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
	Stack st;
	st.StackInit();
	st.StackPush(1);
	st.StackPush(2);
	return 0;
}