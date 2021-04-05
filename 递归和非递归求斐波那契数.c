#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//int Fact(int n)
//{
//	int a = 1;
//	int b = 2;
//	int c = b;
//	if (n == 1 || n == 2)
//	{
//		return n;
//	}
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return b;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fact(n);
//	printf("%d\n", ret);
//	return 0;
//}

int Fact(int n)
{
	if (n <= 2)
	{
		return n;
	}
	else
	{
		return Fact(n - 1) + Fact(n - 2);
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fact(n);
	printf("%d\n", ret);
	return 0;
}