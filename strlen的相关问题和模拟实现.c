#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
//#include<string.h>
//int main()  //strlen的返回值是一个size_t无符号的，且strlen的结束标志是'\0'
//{
//	if (strlen("abc") - strlen("abcdef") > 0) 
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("</n");
//	}
//	return 0;
//}
 
//strlen三种实现方法

//int my_strlen(const char* arr) //1.计数器方式
//{
//  assert(arr);
//	int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		*arr++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//int my_strlen(const char* arr) //2.递归方式
//{
//  assert(arr);
//	if (*arr != '\0')
//	{
//		return(1 + my_strlen(arr + 1));// arr+1意思是指针位置向后移一位
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

int my_strlen(const char* arr)  //指针减去指针是指针和指针中间的元素个数
{
	assert(arr);
	const char* start = arr;
	const char* end = arr;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;
}
int main()
{
	char arr[] = "abc";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}