#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	int line = 0;
	scanf("%d", &line);
	int i = 0;
	int j = 0;
	//打印上三角一共有几行
	for (i = 0; i < line; i++) 
	{
		//打印上三角每行有几个空格
		for (j = 0; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		//打印上三角每行有几个*
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//打印下三角一共有几行
	for (i = 0; i < line - 1; i++)
	{
		//打印下三角每行的空格
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		//打印下三角每行的*
		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}