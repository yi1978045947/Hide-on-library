#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main() //memmove重叠拷贝内存块
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	memmove(arr + 2, arr, 32);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//使用memmove应该注意的地方
//1.如果dest落在src的左边时候，从前向后拷贝
//2.如果dest落在src的右边时候，从后向前拷贝
//3.和memcpy的差别就是memmove函数处理的源内存块和目标内存块是可以重叠的。
//4.如果源空间和目标空间出现重叠，就得使用memmove函数处理。

void* my_memmove(void* arr1, const void* arr2, size_t count)
{
	void* ret = arr1;
	assert(arr1&&arr2);
	if (arr1 < arr2) //从前向后拷贝
	{
		while (count--)
		{
			*(char*)arr1 = *(char*)arr2;
			((char*)arr1)++;
			((char*)arr2)++;
		}
	}
	else //从后向前拷贝
	{
		while (count--)
		{
			*((char*)arr1 + count) = *((char*)arr2 + count);  //根据count来实现向后拷贝
		}
	}
	return ret;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	my_memmove(arr + 2, arr, 24);
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
//标准规定下memcpy内存函数可以实现不重叠拷贝
//VS规定中memcpy函数可以实现重叠拷贝
//但我们实现重叠拷贝还是用memmove函数