#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
//#include<string.h>
//int main()  //strlen�ķ���ֵ��һ��size_t�޷��ŵģ���strlen�Ľ�����־��'\0'
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
 
//strlen����ʵ�ַ���

//int my_strlen(const char* arr) //1.��������ʽ
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

//int my_strlen(const char* arr) //2.�ݹ鷽ʽ
//{
//  assert(arr);
//	if (*arr != '\0')
//	{
//		return(1 + my_strlen(arr + 1));// arr+1��˼��ָ��λ�������һλ
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

int my_strlen(const char* arr)  //ָ���ȥָ����ָ���ָ���м��Ԫ�ظ���
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