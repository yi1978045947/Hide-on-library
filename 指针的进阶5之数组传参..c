#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//一维数组传参
void test1(int arr1[])
{

}
void test1(int arr1[10])
{

}
void test1(int* arr1)
{

}
void test2(int *arr2[20])
{

}
void test2(int **arr2) //指针数组传参，传参的是首元素地址，首元素地址类型是int*,所以用int** 来接收
{

}

//二维数组传参
void test3(int arr[3][5])
{

}
void test3(int arr3[][]) //错误的写法->,行可以不写,列不能不写
{

}
void test3(int arr3[][5])
{

}
void test3(int* arr3) //错误的写法，arr3是一个二维数组，不能用整形指针来接收
{

}
void test3(int* arr3[5]) //错误的写法，arr3是一个二维数组，不能一个指针数组来接收
{

}
void test3(int(*arr3)[5]) //arr3是一个指针，指向的arr3有个元素，每个元素类型是int类型
{

}
void test3(int** arr3)  //错误的写法，二级指针是用来接收一级指针的地址
{

}
int main()
{
	//一维数组传参
	int arr1[10] = { 0 };
	int* arr2[20] = { 0 };
	test1(arr1);
	test2(arr2);
	//二维数组传参
	int arr3[3][5] = { 0 };
	test3(arr3);
	return 0;
}