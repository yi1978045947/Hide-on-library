#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	//函数指针
	int(*p)(int, int);
	//函数指针数组
	int(*pArr[4])(int, int);
	//ppArr是指向函数指针数组的指针,指向pArr这个数组，数组的每个元素都是是函数指针
	int(*(*ppArr)[4])(int, int) = &pArr;
	return 0;
}