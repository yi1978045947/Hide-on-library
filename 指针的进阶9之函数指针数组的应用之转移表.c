#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
void menu()
{
	printf("*****************************\n");
	printf("*****1.ADD    2.Sub      ****\n");
	printf("*****3.Mul    4.Div      ****\n");
	printf("*****         0.Exit     ****\n");
	printf("*****************************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x*y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	int(*pfarr[])(int, int) = { 0, Add, Sub, Mul, Div };  //函数指针数组的应用->转移表
	//do
	//{
	//	menu();
	//	printf("输入你的选择:>");
	//	scanf("%d", &input);
	//	switch (input)
	//	{
	//	case 1:
	//		printf("请输入两个操作数:>");
	//		scanf("%d%d", &x, &y);
	//		ret = Add(x, y);
	//		printf("结果是:%d\n", ret);
	//		break;
	//	case 2:
	//		printf("请输入两个操作数:>");
	//		scanf("%d%d", &x, &y);
	//		ret = Sub(x, y);
	//		printf("结果是:%d\n", ret);
	//		break;
	//	case 3:
	//		printf("请输入两个操作数:>");
	//		scanf("%d%d", &x, &y);
	//		ret = Mul(x, y);
	//		printf("结果是:%d\n",ret);
	//		break;
	//	case 4:
	//		printf("请输入两个操作数:>");
	//		scanf("%d%d", &x, &y);
	//		ret = Div(x, y);
	//		printf("结果是:%d\n", ret);
	//		break;
	//	case 0:
	//		printf("退出程序!\n");
	//		exit(1);
	//	default:
	//		printf("你输入的选择有错误,请重新输入!\n");
	//		break;
	//	}
	//} while (input);
	do
	{
		menu();
		printf("请输入你的选择:>");
		scanf("%d", &input);
		if (input == 0)
		{
			printf("退出程序!\n");
			break;
		}
		else if (input > 0 && input <= 4)
		{
			printf("请输入两个操作数:");
			scanf("%d%d", &x, &y);
			ret = pfarr[input](x, y);
			printf("结果是:%d\n", ret);
		}
	} while (input);
	return 0;
}