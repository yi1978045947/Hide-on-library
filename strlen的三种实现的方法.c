#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
//int my_strlen(char* arr)  ����������
//{
//	assert(arr != NULL);
//	int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "bit";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}
//int my_strlen(char arr[]) �ݹ鷽��
//{
//	if (*arr != '\0')
//	{
//		return (1 + my_strlen(arr + 1));
//	}
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = "bit";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}
int my_strlen(char arr[])  //ָ���ȥָ��õ�����ָ���ָ��֮���Ԫ�ظ���
{
	char* start = arr;
	char* end = arr;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;
}
int main()
{
	char arr[] = "bit";
	int ret = my_strlen(arr);
	printf("%d\n", ret);
	return 0;
}