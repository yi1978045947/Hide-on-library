#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void print(int* pa, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(pa + i));
	}
	printf("\n");
}
void test1(int** pb)
{

}
void test2(int** pc)
{

}
int main()
{
	int arr1[] = { 1, 2, 4, 5, 6, 7, 8, 9, 10 };
	int* pa = &arr1;
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	//一级指针pa,传给函数
	print(pa, sz);
	//二级指针传参,二级指针来接收
	int i = 0;
	int* pb = &i;
	int** pc = &pb;
	test1(&pb); //传一级指针的地址
	test2(pc); //传二级指针pc
	return 0;
}