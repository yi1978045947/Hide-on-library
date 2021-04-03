#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)
		{
			count++;
			printf("%d ", i);
		}
		if (i / 10 == 9)
		{
			count++;
			printf("%d ", i);
		}
	}
	printf("%d\n", count);
	return 0;
}