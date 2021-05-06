#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	int a = 0; //百位
	int b = 0; //十位
	int c = 0; //个位
	for (int i = 100; i <= 999; i++)
	{
		//获取三位数每一位
		a = (i / 100);
		b = (i / 10) % 10;
		c = i % 10;
		if (a*a*a + b*b*b + c*c*c == i)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}