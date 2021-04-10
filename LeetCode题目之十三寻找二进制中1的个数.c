#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int FindKey1(int a)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if ((a >> i) & 1 == 1)
		{
			count++;
		}
	}
	return count;
}
int FindKey2(int a)
{
	int count = 0;
	while (a)
	{
		a = a&(a - 1);
		count++;
	}
	return count;
}
int FindKey3(int a)
{
	int count = 0;
	while (a)
	{
		if (a % 2 == 1)
		{
			count++;
			a = a / 2;
		}
	}
	return count;
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	int count = FindKey3(a);
	int sum = FindKey2(a);
	int ret = FindKey1(a);
	printf("%d\n", count);
	printf("%d\n", sum);
	printf("%d\n", ret);
	return 0;
}