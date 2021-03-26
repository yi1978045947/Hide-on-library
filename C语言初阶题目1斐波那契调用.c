#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int g_cnt = 0;  //定义一个全局变量 g_cnt
int fib(int n)
{
	g_cnt++;
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return 2;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
	//求斐波那契数调用的次数
	//5 4 4 3 4 3 3 2
	//4 3 3 2 3 2 2 1 3 2 2 1 2 1 1 0
	//3 2 2 1 2 1 1 0 2 1 1 0 1 0 2 1 1 0 1 0 1 0
	//2 1 1 0 1 0 1 0 1 0 1 0
	//1 0
}
int main()
{
	fib(8);
	printf("%d\n", g_cnt);
	return 0;
}