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
	Stack st; //���ʵ����������һ������st
	std::cout << sizeof(st) << std::endl;
	std::cout << sizeof(A1) << std::endl;
	std::cout << sizeof(A2) << std::endl;
	return 0;
}
//A1��A2����û�г�Ա������һ��ֻ�г�Ա��������Ա���������ڴ��й�������Ρ�
//��СΪ1����1���ֽڲ���Ϊ�˴洢������ռλ����ʾ������ڹ���