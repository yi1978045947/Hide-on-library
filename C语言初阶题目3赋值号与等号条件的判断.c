#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	int x = 0;
	int y = 0;
	int count = 0;
	for (x = 0, y = 0; (y = 123) && (x < 4); x++)  //注意y=123是赋值号，不是等于号
	{
		count++;
	}
	printf("%d\n", count);
	return 0;
}