#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int fib(int n)
{
	int a = 1;
	int b = 2;
	int c = 0;
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 1;
	}
	else if (n == 3)
	{
		return 2;
	}
	while (n>3)
	{
		c = (a + b) % 1000000007;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = fib(n);
	printf("%d\n", ret);
	return 0;
}