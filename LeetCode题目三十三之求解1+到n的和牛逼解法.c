#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int sumNums(int n)
{
	n && (n = n + sumNums(n - 1));
	return n;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = sumNums(n);
	printf("%d\n", ret);
	return 0;
}