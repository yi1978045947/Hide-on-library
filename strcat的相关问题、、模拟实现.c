#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main() //�ַ���׷��
//{
//	char arr1[20] = "bit ";
//	char arr2[] = "education";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//Դ�ַ��������� '\0' ������
//�ὫԴ�ַ����е� '\0' ������Ŀ��ռ䡣
//Ŀ��ռ�����㹻����ȷ���ܴ��Դ�ַ�����
//Ŀ��ռ����ɱ䡣
//ѧ��ģ��ʵ�֡�

char* my_strcat(char* arr1,const char* arr2)
{
	assert(arr1&&arr2);
	char* ret = arr1;
	while (*arr1!='\0') //�ҵ�Ŀ��ռ��\0
	{
		arr1++;
	}
	while (*arr1++ = *arr2++)//ʵ��׷��
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

