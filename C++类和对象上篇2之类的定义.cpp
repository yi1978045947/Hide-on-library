#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
typedef int STDateType;
class Stack
{
public:
	//��Ա����������
	void StackInit(int initSize = 4);
	void StackPush(STDateType x);

	//��Ա����������
	STDateType* a;
	int size;
	int capacity;
};

//��Ա�����Ķ���
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