#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//void left_move(char *arr, int k) //����ת�ַ���
//{
//	assert(arr != NULL);
//	int i = 0;
//	int len = strlen(arr);
//	for (i = 0; i < k; k++)
//	{
//		char tmp = *arr;
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[j] = tmp;
//	}
//}
//int main()
//{
//	int k = 0;
//	scanf("%d", &k);
//	char arr[] = "biteducation";
//	left_move(arr,k);
//	printf("%s\n", arr);
//	return 0;
//}


//void left_move(char *arr1, int k) //����ת�ַ���дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ���,���磺����s1 = AABCD��s2 = BCDAA������1����s1 = abcd��s2 = ACBD������0.
//{
//	assert(arr1 != NULL);
//	int i = 0;
//	int len = strlen(arr1);
//	for (i = 0; i < k; k++)
//	{
//		char tmp = *arr1;
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			arr1[j] = arr1[j + 1];
//		}
//		arr1[len-1] = tmp;
//	}
//}
//int is_left_move(char* arr1, char* arr2)
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	int len = strlen(arr1);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		left_move(arr1, 1);
//		int ret = strcmp(arr1, arr2);
//		if (ret == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[] = "biteeducation";
//	char arr2[] = "educationbite";
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//	{
//		printf("YES\n");
//	}
//	else
//	{
//		printf("NO\n");
//	}
//	return 0;
//}
int FindNum(int arr[3][3], int k, int* px,int* py )//����Ҫ����ַ��ȥ�ſ��Ըı������ֵ
{
	int x = 0;
	int y = *py - 1;
	while (x < *px - 1 && y>=0)
	{
		if (arr[x][y]>k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9, } };
	int k = 4;
	int x = 3;
	int y = 3;
	int ret = FindNum(arr, k, &x, &y);
	if (ret == 1)
	{
		printf("�ҵ���\n");
	}
	else
	{
		printf("�Ҳ���\n");
	}
	return 0;
}