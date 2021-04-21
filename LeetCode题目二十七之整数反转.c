#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<math.h>
int reverse(int x)
{
	int sum = 0;
	while (x)
	{
		sum = sum * 10 + x % 10;
		x = x / 10;
	}
	if (sum > pow(2, 31) || sum < pow(-2, 31) - 1)
	{
		return 0;
	}
	return sum;
}
int main()
{
	int x = 0;
	scanf("%d", &x);
	int ret = reverse(x);
	printf("%d\n", ret);
	return 0;
}