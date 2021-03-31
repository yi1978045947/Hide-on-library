#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void test1()  //test1就是回调函数
{
	printf("bit education!\n");
}
void test2(void(*p)()) //用函数指针来接收  -->通过指针p来调用函数test1，test1就是回调函数
{
	p();
}
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
void calc(int(*pfArr)(int,int)) //把函数的地址传过去,用函数指针来接收，那么被接受者就是回调函数
{
	int x = 0;
	int y = 0;
	int ret = 0;
	printf("请输入两个操作数:>");
	scanf("%d%d", &x, &y);
	ret = pfArr(x, y);
	printf("结果是:%d\n", ret);
}
int main()
{
	int input = 0;
	test2(test1); //把test1函数的地址传给test2<-->函数名就是函数地址
	do
	{
		menu();
		printf("请输入你的选择:>");
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
			printf("退出程序!\n");
			break;
		default :
			printf("你输入的选择有错误,请重新输入!\n");
			break;
		}

	} while (input);
	return 0;
}