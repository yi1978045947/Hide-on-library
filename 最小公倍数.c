#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	int max = a > b ? a : b;
//	while (max%a != 0 || max%b != 0)
//	{
//		max++;
//	}
//	printf("%d\n", max);
//	return 0;
//}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	int i = 0;
	while (a*i%b != 0)
	{
		i++;
	}
	printf("%d\n", a*i);
	return 0;
}
