#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main()  //strcmp�ȽϵĲ����ַ����ĳ��ȣ��Ƚϵ����ַ������ַ���Ӧ��ASCIIֵ
//{
//	char arr1[] = "bit";
//	char arr2[] = "education";
//	int ret =strcmp(arr1, arr2);
//	printf("%d\n", ret);
//	return 0;
//}
//׼�涨��
//��һ���ַ������ڵڶ����ַ������򷵻ش���0������
//��һ���ַ������ڵڶ����ַ������򷵻�0
//��һ���ַ���С�ڵڶ����ַ������򷵻�С��0������
//��ô����ж������ַ�����

//int my_strcmp(const char* arr1, const char* arr2)  //1.һ��ģ��ʵ��
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
int my_strcmp(const char* arr1, const char* arr2) //2.�ڶ���ģ��ʵ��
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
	int ret = my_strcmp(arr1, arr2); //�ַ����ȽϺ���
	printf("%d\n", ret);
	return 0;
}