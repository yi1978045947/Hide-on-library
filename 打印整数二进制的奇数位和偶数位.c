#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	printf("����λ:>");
	for (i = 0; i < 32; i+=2)
	{
		printf("%d ", (n >> i & 1));
	}
	printf("\n");
	printf("ż��λ:>");
	for (i = 2; i < 31; i += 2)
	{
		printf("%d ", (n >> i & 1));
	}
	printf("\n");
	return 0;
}