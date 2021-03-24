#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int jump(int n)
{
	if (n == 1 || n == 2)
	{
		return n;  //n==1时，有一种跳法，n==2时，有两种跳法
	}
	else          //n为3开始递归
	{
		return jump(n - 1) + jump(n - 2);
	}
}
int main()
{
	int n = 0;
	printf("请输入跳的台阶数:>");
	scanf("%d", &n);
	int sum = jump(n);
	printf("一共有%d种方法!\n",sum);
	return 0;
}