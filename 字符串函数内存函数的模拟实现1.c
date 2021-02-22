#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
//char* my_strstr(char* arr1, char* arr2) 模拟实现字符串查找函数
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	char* p1 = (char*)arr1;
//	char* p2 = (char*)arr2;
//	char* p3 = NULL;
//	if (*arr2 == '\0')
//	{
//		printf("查找的字符串不存在!\n");
//	}
//	while (*p1)
//	{
//		p3 = p1;
//		p2 = arr2;
//		while (*p1&&p2 && (*p1 == *p2))
//		{
//			p1++;
//			p2++;
//		}
//		if (*p2 == "\0")
//		{
//			return p1;
//		}
//		p1++;
//	}
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "def";
//	char* ret = my_strstr(arr1, arr2);
//	if (ret == NULL)
//	{
//		printf("查找的字符串不存在\n");
//	}
//	else
//	{
//		printf("查找的字符串存在!\n");
//	}
//	return 0;
//}

//int my_strlen(char* arr )模拟实现求字符串的长度
//{
//	int count = 0;
//	assert(arr != NULL);
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

char* my_strcpy(char* arr1, char* arr2)
{
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	char* ret = arr1;
	while (*arr2 != '\0')
	{
		*arr1 = *arr2;
		arr1++;
		arr2++;
	}
	*arr1 = *arr2;
	return ret;
}
int main()
{
	char arr1[] = "education";
	char arr2[] = "bit";
	char* ret=my_strcpy(arr1, arr2);
	printf("%s\n", ret);
	return 0;
}