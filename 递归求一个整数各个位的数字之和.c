#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int FindKey(int n)
{
	if (n < 10)
	{
		return n;
	}
	else
	{
		return FindKey(n / 10) + FindKey(n % 10); //³ý10Ä£10
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = FindKey(n);
	printf("%d\n", ret);
	return 0;
}