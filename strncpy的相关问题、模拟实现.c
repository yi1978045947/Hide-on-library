#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//int main()  //���������ƵĿ���������������strcpy��һ��
//{
//	char arr1[30] = "bit";
//	char arr2[] = "education";
//	strncpy(arr1, arr2, 2);
//	printf("%s\n", arr1);
//	return 0;
//}

//����num���ַ���Դ�ַ�����Ŀ��ռ䡣
//���Դ�ַ����ĳ���С��num���򿽱���Դ�ַ���֮����Ŀ�����׷��һ��0��ֱ��num��

char* my_strncpy(char* arr1, const char* arr2,int nums)
{
	assert(arr1&&arr2);
	char* ret = arr1;
	while (nums) //����arr2���ַ���arr1����ȥ,ʣ��\0û�п���
	{
		*arr1++ = *arr2++;
		nums--;
	}
	while (nums) //����\0��ȥ
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