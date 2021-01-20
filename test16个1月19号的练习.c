#define _CRT_SECURE_NO_WARNINGS   1
//#include <stdio.h>  //两端的字母向中间汇聚，编写代码，演示多个字符从两端移动
//#include<stdlib.h>
//#include<Windows.h>
//#include<string.h>
//int main()
//{
//	char arr1[] = "I love programmer!!!";
//	char arr2[] = "###################";
//	int sz = strlen(arr1) - 1;
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//	return 0;
//}
//#include<stdio.h> 理解strcmp函数的作用
//#include<string.h>
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:>");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("登入成功!\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误,请重新输入!\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("用户密码输入错误超过3次，用户已锁定!\n");
//	}
//	return 0;
//}