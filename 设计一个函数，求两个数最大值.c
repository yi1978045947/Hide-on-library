#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int fun(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	int ret = fun(a, b);
	printf("%d\n", ret);
	return 0;
}