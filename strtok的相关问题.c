#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
int main() //strtok�����ַ����ָ��ַ���
{
	char arr1[] = "1978045947@qq.com";
	char arr2[40] = { 0 };
	char* pa = "@.";
	strcpy(arr2, arr1);
	//printf("%s\n", strtok(arr2, pa));
	//printf("%s\n", strtok(NULL, pa));
	//printf("%s\n", strtok(NULL, pa));
	char* ret = NULL;
	for (ret = strtok(arr2, pa); ret != NULL; ret =strtok(NULL, pa)) //1.��һ�δ��ǿ�ָ�룬�ڶ��δ���ָ�� 2.strtok�����ĵ�һ��������Ϊ NULL ���������ҵ�str�е�һ����ǣ�strtok���������������ַ����е�λ�á�3.strtok�����ĵ�һ������Ϊ NULL ����������ͬһ���ַ����б������λ�ÿ�ʼ��������һ����ǡ�
	{
		printf("%s\n", ret);
	}
	return 0;
}