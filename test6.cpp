#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main()
{
	char  a;
	printf("������һ������");
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