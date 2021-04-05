#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int i = 0;
//	int n = 0;
//	scanf("%d%d", &i, &n);
//	int sum = pow(i, n);
//	printf("%d\n", sum);
//	return 0;
//}

int my_pow(int i, int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return i*my_pow(i, n - 1);
	}
}
int main()
{
	int i = 0;
	int n = 0;
	scanf("%d%d", &i, &n);
	int ret = my_pow(i, n);
	printf("%d\n", ret);
	return 0;
}