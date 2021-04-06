#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void koujie(int i)
{
	int a = 0;
	int b = 0;
	for (a = 1; a <= i; a++)
	{
		for (b = 1; b <= a; b++)
		{
			printf("%d*%d=%-3d", a, b, a*b);
		}
		printf("\n");
	}
}
int main()
{
	int i = 0;
	scanf("%d", &i);
	koujie(i);
	return 0;
}