#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int FindKey(int n)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (((n >> i) & 1 )== 1)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = FindKey(n);
	printf("%d\n", ret);
	return 0;
}