#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main() //�ַ���׷�Ӻ���������������
//{
//	char arr1[30] = "bit ";
//	char arr2[] = "education";
//	strncat(arr1, arr2, 9); //׷����֮��Ҳ���\0׷�ӹ�ȥ��������ַ��������Ჹ��\0
//	printf("%s\n", arr1);
//	return 0;	
//}

char* my_strncat(char* arr1, const char* arr2, int count)
{
	assert(arr1&&arr2);
	char* ret = arr1;
	while (*arr1 != '\0')
	{
		arr1++;
	}
	while (count--)
	{
		if (!(*arr1++ = *arr2))
		{
			return ret;
		}
	}
	*arr1 = '\0';
	return ret;
}
int main()
{
	char arr1[30] = "bit ";
	char arr2[] = "education";
	my_strncat(arr1, arr2, 1);
	printf("%s\n", arr1);
	return 0;
}