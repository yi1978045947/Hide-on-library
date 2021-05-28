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
class  A1
{

};
class A2
{
	void fun()
	{

	}
};

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
	Stack st; //类的实例化，创建一个对象st
	std::cout << sizeof(st) << std::endl;
	std::cout << sizeof(A1) << std::endl;
	std::cout << sizeof(A2) << std::endl;
	return 0;
}
//A1和A2两者没有成员变量，一个只有成员函数，成员函数存在内存中公共代码段。
//大小为1，给1个字节不是为了存储，而是占位，表示对象存在过。