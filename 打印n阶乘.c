#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int jiecheng(int n)  //递归方法
{
	if (n < 2)
	{
		return n;
	}
	else
	{
		return n*jiecheng(n - 1);
	}
}
int main()    
{
	int n = 0;
	int sum = 1;
	scanf("%d", &n);
	int i = 0;
	for (i = 1; i <= n; i++)  //普通方法
	{
		sum = sum*i;
	}
	int ret = jiecheng(n);;
	printf("%d\n", ret);
	printf("%d\n", sum);
	return 0;
}