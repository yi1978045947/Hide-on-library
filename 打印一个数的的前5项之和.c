#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int sum(int i,int n)
{
	int j = 0;
	int tmp = 0;
	int totalsum = 0;
	for (j = 0; j < n; j++)
	{
		tmp = tmp * 10 + i;
		totalsum = totalsum + tmp;
	}
	return totalsum;
}
int main()
{
	//求数字i的前n项之和，例如，2的前五项之和，2+22+222+2222+22222
	int i = 0; //数字i
	int n = 0; //位数n  
	scanf("%d%d", &i,&n);
	int ret = sum(i,n);
	printf("%d\n", ret);
	return 0;
}