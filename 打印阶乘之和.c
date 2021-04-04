#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int jiecheng(int n)
{
	int i = 0;
	int j = 0;
	int sum = 1;
	int totalsum = 0;
	for (i = 1; i <= n; i++)
	{
		sum = 1;
		for (j = 1; j <= i; j++)
		{
			sum = sum*j;
		}
		totalsum = totalsum + sum;
	}
	return totalsum;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = jiecheng(n);
	printf("%d\n", ret);
	return 0;
}