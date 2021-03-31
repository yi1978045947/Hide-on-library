#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int main()  //函数指针数组
{
	int a = 10;
	int b = 20;
	int* arr[] = { &a, &b };
	//函数指针->存放函数的地址
	int(*pf1)(int, int) = Add;
	int(*pf2)(int, int) = Sub;
	//函数指针数组->存放函数指针的数组
	int(*pfarr[2])(int, int) = { Add, Sub };
	return 0;
}