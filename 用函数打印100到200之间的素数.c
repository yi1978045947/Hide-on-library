#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<math.h>
int is_prime(int n)
{
	int i = 0;
	for (i = 2; i <= sqrt(n); i += 2)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n = 0;
	for (n = 100; n <= 200; n++)
	{
		if (is_prime(n)==1)
		{
			printf("%d ", n);
		}
	}
	printf("\n");
	return 0;
}