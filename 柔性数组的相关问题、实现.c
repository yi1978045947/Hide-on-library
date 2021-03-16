#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct a   //计算包含柔性数组成员的结构体的大小的时候，不包含柔性数组成员，柔性数组成员的大小时可变的
{
	int i;
	int arr[];
};
struct b 
{
	char c;
	int i;
	int arr[];
};
struct c
{
	int a;
	int* arr;
};
int main()
{
	printf("%d\n", sizeof(struct a));
	printf("%d\n", sizeof(struct b)); //柔性数组受内存对齐影响  //柔性数组成员不是创建的
	printf("%d\n", sizeof(struct c));
	struct a* pa = (struct a*)malloc(sizeof(struct a) + sizeof(int)* 10);
	pa->i = 100;
	int b = 0;
	for (b = 0; b < 10; b++)
	{
		pa->arr[b] = b;
	}
	for (b = 0; b < 10; b++)
	{
		printf("%d ", pa->arr[b]);
	}
	printf("\n");
	for (b = 0; b < 10; b++)
	{
		printf("%d ", *(pa + b));//此时因为先开辟了空间，所以第一个空间是结构体的空间
	}
	printf("\n");
	free(pa);
	pa = NULL;
	struct c* pb = (struct c*)malloc(sizeof(struct c));
	pb->arr = (int*)malloc(sizeof(int));
	free(pb);	
	free(pb->arr);
	pb = NULL;
	pb->arr = NULL;
	return 0;
}
//1.结构中的柔性数组成员前面必须至少一个其他成员。
//2.sizeof 返回的这种结构大小不包括柔性数组的内存。
//3.包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。