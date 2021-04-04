#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main()
{
	char  a;
	printf("请输入一个数：");
	scanf("%c", &a);
	if (a <= 91)
	{
		a = a + 32;
		printf("%c\n", a);
	}
	else
	{
		a = a - 32;
		printf("%c\n", a);
	}
	return 0;
}