#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int Jump(int n)
{
	int a = 1;
	int b = 2;
	int c = a;
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	while (n > 2)  //赋值法解决效率比递归方法更高!
	{
		c = a + b;
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
	int sum = 0;
	sum = Jump(n);
	printf("%d\n", sum);
	return 0;
}