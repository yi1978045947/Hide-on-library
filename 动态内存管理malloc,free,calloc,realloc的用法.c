#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
//int main()  //malloc函数的使用
//{
//	/*int nums = 0;
//	scanf("%d", &nums);*/
//	int arr[10] = { 0 }; //在栈上申请了40个字节的空间
//	int* pa = (int*)malloc(sizeof(int)* 10); //在堆区申请40个字节的空间
//	if (pa == NULL)//开辟失败
//	{
//		printf("内存开辟失败!\n");
//	}
//	else //开辟成功
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(pa + i) = 0;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", pa[i]);
//		}
//		printf("\n");
//		//不在使用指针pa所指向的动态内存
//		//手动释放动态开辟的内存
//		free(pa);
//		pa = NULL;
//	}
//	return 0;
//}

//int main()  //calloc函数的使用
//{
//	int* pa = (int*)calloc(10, sizeof(int)); //calloc函数参数类型(参数个数，参数大小(字节为单位))
//	if (pa == NULL)
//	{
//		printf("%s\n", strerror(errno));//开辟失败，用strerror返回错误的信息
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(pa + 1));
//		}
//		printf("\n");
//		//空间不够了，增加空间，调整空间的大小用realloc
//		int* pb = (int*)realloc(pa, 80); //用新的指针来接收旧的指针,realloc函数参数包括新的指针pa指向新的内存，和size调整后的新大小。
//		if (pb != NULL)
//		{
//			pa = pb;
//		}
//		for (i = 0; i < 20; i++)
//		{
//			printf("%d ", pb[i]);
//		}
//		printf("\n");
//		free(pa);
//		pa = NULL;
//	}
//	return 0;
//}

//malloc函数和calloc函数的区别
//1.函数参数不相同，malloc函数参数只有一个参数个数，calloc函数包括参数个数和参数大小，单位是字节
//2.初始化不同,malloc函数开辟的空间时候不初始化的，而calloc函数开辟的空间是初始化的

//动态内存错误
//1.对NULL指针进行解引用操作
//int main()
//{
//	int* pa = (int*)malloc(INT_MAX);
//	if (pa == NULL)//没有判断pa是否为空
//	{
//		printf("开辟失败!\n");
//	}
//	else
//	{
//		*pa = 0;
//		free(pa);
//		pa = NULL;
//	}
//	return 0;
//}

//2.对开辟空间的越界访问
//int main()
//{
//	int* pa =(int*) malloc(10 * sizeof(int));
//	if (pa == NULL)
//	{
//		printf("开辟失败!\n");
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i <= 11; i++)//开辟空间时越界访问
//		{
//			*(pa + i) = 0;
//		}
//		for (i = 0; i <= 11; i++)
//		{
//			printf("%d ", pa[i]);
//		}
//		free(pa);
//		pa = NULL;
//	}
//	return 0;
//}

//3.对非动态开辟的空间使用free释放
//int main()
//{
//	int a = 1;
//	int* pa = &a;
//	free(pa);
//	pa = NULL;
//	free(pa);
//}

//4.使用free释放一块动态内存开辟的空间
//int main()
//{
//	int* pa = (int*)malloc(sizeof(int)* 10);
//	if (pa == NULL)
//	{
//		printf("开辟空间失败!\n");
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			*pa++ = 0;
//		}
//		for (i = 0; i < 5; i++)
//		{
//			printf("%d ", pa[i]);
//		}
//		free(pa);
//		pa = NULL;
//	}
//	return 0;
//}

////5.对同一块内存多次释放
//int main()
//{
//	int* pa = (int*)malloc(sizeof(int)* 10);
//	if (pa == NULL)
//	{
//		printf("开辟失败!\n");
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(pa + i) = 0;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", pa[i]);
//		}
//		free(pa);
//		free(pa);
//		pa = NULL;
//	}
//	return 0;
//}

//6.对开辟的内存空间忘记释放,内存泄漏问题
int main()
{
	int* pa = (int*)malloc(sizeof(int)* 10);
	if (pa == NULL)
	{
		printf("开辟失败!\n");
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(pa + i) = 0;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", pa[i]);
		}
		return 0;
		//未使用free来释放开辟的内存空间
	}
	return 0;
}