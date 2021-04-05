#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char arr[100] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:>");
		scanf("%s", arr);
		if (strcmp(arr, "abc") == 0)
		{
			printf("登录成功!\n");
			break;
		}
		else
		{
			if (i == 2)
			{
				printf("输入三次错误，退出输入!\n");
				break;
			}
			printf("密码错误,请重新输入\n");
		}
	}
	return 0;
}