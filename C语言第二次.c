#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>

//int main()  //输入缓冲器的概念,要先把\n字符读取掉
//{
//	char password[20];
//	printf("请输入你的密码:>");
//	scanf("%s", password);
//	printf("请确认(Y/N):>");
//	getchar();
//	int ch = getchar();
//	if (ch == 'Y')
//	{
//		printf("确认成功!\n");
//	}
//	else
//	{
//		printf("确认失败!\n");
//	}
//	return 0;
//}

//int main() //7.打印飞机图案
//{
//	printf("     **     \n");
//	printf("     **     \n");
//	printf("************\n");
//	printf("************\n");
//	printf("    *  *    \n");
//	printf("    *  *    \n");
//	return 0;
//}

//int main() //8.十六进制数ABCDEF打印成十进制数，指定域宽为15
//{
//	printf("%15d\n", 0xABCDEF);
//	return 0;
//}

//int main()  //9.打印hello world的返回值,printf返回的是字符的个数
//{
//	/*printf("%d\n", (printf("%d", printf("%d"), 43)));*/
//	int ret = printf("hello world");
//	printf("\n");
//	printf("%d\n", ret);
//	return 0;
//}

//int main() //10.学生基本信息的输入输出，依次输入学生，学号，三科成绩
//{
//	int id = 0;
//	double C = 0.0;
//	double math = 0.0;
//	double chinese = 0.0;
//	scanf("%d%lf%lf%lf", &id, &C, &math, &chinese);
//	printf("The each subject score of NO. %d is %.2lf,%.2lf,%.2lf\n", id, C, math, chinese);
//	return 0;
//}

//int main() //11.多组输入，每组包括一个字符
//{
//	int ch = 0;//字符阿斯科马是正数可以存放到int类型中
//	while ((ch = getchar()) != EOF)
//	{
//		if ((ch >= 'A'&&ch<='Z')||(ch>='a'&&ch<='z'))
//		{
//			printf("Y\n");
//		}
//		else
//		{
//			printf("N\n");
//		}
//		getchar();//清除缓冲区\n
//	}
//	return 0;
//}

//int main() //12.输入一个字符，构造一个金字塔
//{
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		//打印空格
//		for (j = 0; j < n - i - 1; j++)
//		{
//			printf(" ");
//		}
//		//打印字符
//		for (j = 0; j <= i; j++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main() //13.转换输出题目中给出的所有ASCII码字符
//{
//	char arr[] = { 73, 72, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}

//int main() //14.输入只有一行，出生日期，包括年月日，年月日数字没有分隔符,注意格式控制
//{
//	int year = 0;
//	int month = 0;
//	int date = 0;
//	scanf("%4d%2d%2d", &year, &month, &date);
//	printf("year=%4d\n", year);
//	printf("month=%02d\n", month);
//	printf("date=%02d\n", date);
//	return 0;
//}

int main() //15.多组输入，每一行输入一个整数，求2的n次方
{
	int n = 0;
	int sum = 0;
	while (scanf("%d", &n)!=EOF)
	{
		sum = 1 << n;
	}
	printf("%d\n", sum);
	return 0;
}