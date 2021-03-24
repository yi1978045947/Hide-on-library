#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	char a = 0;
	char ch = 0;
	while ((ch = getchar()) != '\n')
	{
		if (a % 2 != 0 && (ch >= 'a'&&ch <= 'z'))
		{
			ch = ch - 'a' + 'A';
		}
		a++;
		putchar(ch);
	}
	printf("\n");
}
// 类似转换为小写转换为大写