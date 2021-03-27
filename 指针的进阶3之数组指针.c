#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()  //数组指针--指针--指向数组的指针
{
	int arr1[10] = { 0 };

	int(*pa)[10] = &arr1; 
	//&arr取出的是整个数组的地址，pa与*结合是指针，指向的数组arr有10个元素，每个元素类型是int类型

	int* pb[10] = { 0 };
	//这里是指针数组，pa数组中有10个元素，每个元素类型是int* 类型

	char ch[5] = { 0 };
	char(*p3)[5] = &ch;

	//数组名和&数组名
	int arr2[10] = { 1, 2, 3, 4, 5 };
	int* pc = arr2;
	int(*pd)[10] = &arr2;
	printf("%p\n", pc);   //pc指向的是首元素的地址，pc+1是跳过一个整形
	printf("%p\n", pc + 1);
	printf("%p\n", pd);  // pb指向的是一个的数组，pb+1是跳过一个整形数组
	printf("%p\n", pd + 1);
	
	//&(数组名)和sizeof(数组名)是整个数组的地址,除此之外，都是首元素地址
	return 0;
}