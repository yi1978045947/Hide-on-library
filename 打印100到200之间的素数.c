#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	int i = 0;
	int n = 0;
	for (i = 100; i <= 200; i++)
	{
		for (n = 2; n < i ; n++)
		{
			if (i%n == 0)
			{
				break;
			}
		}
		if (n == i)
		{
			printf("%d ", n);
		}
	}
	printf("\n");
	return 0;
}