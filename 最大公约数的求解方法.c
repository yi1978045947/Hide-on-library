#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//int main() //常规方法
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	int min = a > b ? a : b;
//	while (min%a != 0 || min%b != 0)
//	{
//		min++;
//	}
//	printf("%d\n", min);
//	return 0;
//}
int main() //巧妙方法
{
	int a = 0;
	int b = 0;
	int i = 1;
	scanf("%d%d", &a, &b);
	int min = a > b ? a : b;
	while (a*i%b != 0)
	{
		i++;
	}
	printf("%d\n", a*i);
	return 0;
}