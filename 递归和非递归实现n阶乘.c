#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int sum = 1;
//	int j = 0;
//	scanf("%d", &i);
//	for (j = 1; j <= i; j++)
//	{
//		sum = sum*j;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
int jiecheng(int n)
{
	if (n == 1 || n == 2)
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
	scanf("%d", &n);
	int ret = jiecheng(n);
	printf("%d\n", ret);
	return 0;
}