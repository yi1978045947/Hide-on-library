#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void swap(int* a, int* b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	swap(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}