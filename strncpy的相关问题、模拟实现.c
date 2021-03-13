#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//int main()  //长度受限制的拷贝函数，参数比strcpy多一个
//{
//	char arr1[30] = "bit";
//	char arr2[] = "education";
//	strncpy(arr1, arr2, 2);
//	printf("%s\n", arr1);
//	return 0;
//}

//拷贝num个字符从源字符串到目标空间。
//如果源字符串的长度小于num，则拷贝完源字符串之后，在目标后面追加一个0，直到num个

char* my_strncpy(char* arr1, const char* arr2,int nums)
{
	assert(arr1&&arr2);
	char* ret = arr1;
	while (nums) //拷贝arr2的字符到arr1里面去,剩余\0没有拷贝
	{
		*arr1++ = *arr2++;
		nums--;
	}
	while (nums) //拷贝\0过去
	{
		*arr1++ = '\0';
	}
	return ret;
}
int main()
{
	char arr1[20] = "***********";
	char arr2[] = "bit education";
	my_strncpy(arr1, arr2, 5);
	printf("%s\n", arr1);
	return 0;
}