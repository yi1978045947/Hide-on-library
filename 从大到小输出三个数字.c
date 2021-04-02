#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d%d", &a, &b, &c);
	if (a < b)
	{
		int tmp = 0;
		tmp = b;
		b = a;
		a = tmp;
	}
	if (a < c)
	{
		int tmp = 0;
		tmp = c;
		c = a;
		a = tmp;
	}
	if (b < c)
	{
		int tmp = 0;
		tmp = c;
		c = b;
		b = tmp;
	}
	printf("%d %d %d\n", a, b, c);
	return 0;
}