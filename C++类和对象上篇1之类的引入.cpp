#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
typedef int STDateType;
struct Stack
{
	void StackInit(int initSize = 4)
	{
		a = (STDateType*)malloc(sizeof(STDateType)*initSize);
		size = 0;
		capacity = initSize;
	}
	void StackPush(STDateType x)
	{
		a[size] = x;
		size++;
	}
	STDateType* a;
	int size;
	int capacity;
};
int main()
{
	return 0;
}