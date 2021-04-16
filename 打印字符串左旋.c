#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>
void left_move(char* arr, int k,int len)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < k; i++)
	{
		char  ret = *arr; //保存第一个字符到ret里面
		for (j = 0; j < len - 1; j++)
		{
			*(arr + j) = *(arr + j + 1);
		}
		*(arr + len - 1) = ret;
	}
}
int main()
{
	int k = 0;
	char arr[] = "bit education";
	int len = strlen(arr);
	scanf("%d", &k);
	left_move(arr, k,len);
	printf("%s\n", arr);
	return 0;
}