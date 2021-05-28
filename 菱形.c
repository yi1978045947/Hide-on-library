#define _CRT_SECURE_NO_WARNINGS   1
#include <stdio.h>
void main()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5-i; j++)
		{
			printf(" ");
		}
		for (j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4-i; j++)
		{
			printf("*");
		}
		for (j = 0; j < i + 1; j++)
		{
			printf(" ");
		}
		printf("\n");
	}
}