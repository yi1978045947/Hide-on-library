#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void menu()
{
	printf("********1.Add   2.Sub********\n");
	printf("********3.Mul   4.Div********\n");
	printf("********0.Exit     **********\n");
}
int  Add(int x, int y)
{
	return x + y;
}
int  Sub(int x, int y)
{
	return x - y;
}
int  Mul(int x, int y)
{
	return x * y;
}
int  Div(int x, int y)
{
	return x / y;
}
void calc(int (*p)(int x, int y))//传函数地址，传函数数据
{
	int x = 0;
	int y = 0;
	printf("请输入两个数据:");
	scanf("%d%d", &x, &y);
	printf("%d\n", p(x, y));
}
int main()
{
	int input = 0;
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			calc(Add);
			break;
		case 2:
			calc(Sub);
			break;
		case 3:
			calc(Mul);
			break;
		case 4:
			calc(Div);
			break;
		case 0:
			printf("退出!\n");
			break;
		default:
			printf("输入错误，重新输入!\n");
			break;
		}
	} while (input);
	return 0;
}