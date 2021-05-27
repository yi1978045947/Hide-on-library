#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
typedef int STDateType;
class Stack
{
public:
	void StackInit(int initSize = 4);
	void StackPush(STDateType x);
private:
	STDateType* a;
	int size;
	int capacity;
};
void Stack::StackInit(int initSize) //作用域符号::表示StackInit成员函数属于Stack域
{
	a = (STDateType*)malloc(sizeof(STDateType)*initSize);
	size = 0;
	capacity = initSize;
}
void Stack::StackPush(STDateType x)//作用域符号::表示StackPush成员函数属于Stack域
{
	a[size] = x;
	size++;
}
int main()
{
	Stack st;
	st.StackInit();
	st.StackPush(1);
	return 0;
}