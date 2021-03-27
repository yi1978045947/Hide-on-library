#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()  //指针数组--数组--存放指针的数组
{
	char* arr1[10] = { 0 };  
	//arr1数组有10个元素，每个元素是char*类型

	int* arr2[10] = { 0 };  
	//arr2数组有10个元素，每个元素是int*类型

	char** arr3[10] = { 0 };  
	//arr3数组有10个元素，每个元素是char**类型
	return 0;
}