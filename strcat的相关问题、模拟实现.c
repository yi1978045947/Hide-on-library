#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main() //字符串追加
//{
//	char arr1[20] = "bit ";
//	char arr2[] = "education";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//源字符串必须以 '\0' 结束。
//会将源字符串中的 '\0' 拷贝到目标空间。
//目标空间必须足够大，以确保能存放源字符串。
//目标空间必须可变。
//学会模拟实现。

char* my_strcat(char* arr1,const char* arr2)
{
	assert(arr1&&arr2);
	char* ret = arr1;
	while (*arr1!='\0') //找到目标空间的\0
	{
		arr1++;
	}
	while (*arr1++ = *arr2++)//实现追加
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[20] = "bit ";
	char arr2[] = "education";
	my_strcat(arr1, arr2);
	printf("%s\n",arr1);
	return 0;
}

