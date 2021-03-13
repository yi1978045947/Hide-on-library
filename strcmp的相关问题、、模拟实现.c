#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main()  //strcmp比较的不是字符串的长度，比较的是字符串中字符对应的ASCII值
//{
//	char arr1[] = "bit";
//	char arr2[] = "education";
//	int ret =strcmp(arr1, arr2);
//	printf("%d\n", ret);
//	return 0;
//}
//准规定：
//第一个字符串大于第二个字符串，则返回大于0的数字
//第一个字符串等于第二个字符串，则返回0
//第一个字符串小于第二个字符串，则返回小于0的数字
//那么如何判断两个字符串？

//int my_strcmp(const char* arr1, const char* arr2)  //1.一种模拟实现
//{
//	assert(arr1&&arr2);
//	while (*arr1 == *arr2)
//	{
//		arr1++;
//		arr2;
//	}
//	if (*arr1 > *arr2)
//	{
//		return 1;
//	}
//	else if (*arr1 == *arr2)
//	{
//		return 0;
//	}
//	else
//	{
//		return -1;
//	}
//}
int my_strcmp(const char* arr1, const char* arr2) //2.第二种模拟实现
{
	assert(arr1&&arr2);
	while (*arr1 == *arr2)
	{
		if (*arr1 != '\0')
		{
			return 0;
		}
	}
	return *arr1 - *arr2;
}
int main()
{
	char arr1[] = "bit";
	char arr2[] = "education";
	int ret = my_strcmp(arr1, arr2); //字符串比较函数
	printf("%d\n", ret);
	return 0;
}