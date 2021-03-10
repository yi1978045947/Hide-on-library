#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()  //输入缓冲器的概念,要先把\n字符读取掉
{
	char password[20];
	printf("请输入你的密码:>");
	scanf("%s", password);
	printf("请确认(Y/N):>");
	getchar();
	int ch = getchar();
	if (ch == 'Y')
	{
		printf("确认成功!\n");
	}
	else
	{
		printf("确认失败!\n");
	}
	return 0;
}