#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void print1(int arr2[3][5], int x, int y)  //普通的二位数组打印，数组传参，数组接收
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
}
void print2(int(*pd)[5], int x, int y) //用数组指针来接收一维数组
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", *((*pd + i) + j)); //(*pd+i)是找到第i行的地址，*((*pd+i)+j)是找到第i行第j列的元素
		}
		printf("\n");
	}
}
int main()  //数组指针的使用->指向数组的指针
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* pa = &arr;
	int(*pb)[10] = &arr;
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(pa + i));
		printf("%d ",(*pb)[i]);  //*pa<==>arr
		printf("%d ", *(*pb + i));
	}
	printf("\n");

	int arr2[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
	//二维数组传参，数组名也是首元素地址，二位数组的首元素是第一行
	//传过去的是第一行的地址->一维数组的地址
	print1(arr2, 3, 5);
	print2(arr2, 3, 5);


	int arr4[5];     //整形数组
	int* arr5[10];   //指针数组，arr5里面有10个元素，每个元素类型是int*
  	int(*pe)[10];    //数组指针，pe指针指向的数组里面有10个元素，每个元素类型是int类型
	int(*pf[10])[5]; //int(*)[5] ,存放数组指针的数组,pf数组中有10个元素，每个元素类型是数组指针，数组指针有5个元素，元素类型是int
	return 0;
}