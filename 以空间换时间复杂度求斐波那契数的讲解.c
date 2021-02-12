#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<malloc.h>
long long* Fibonacci(size_t N)//size_t是无符号的数
{
	unsigned int n = 0;
	long long* FibArray = malloc(sizeof(long long)*(N + 1));//用空间来换时间
	FibArray[0] = 0;
	if (N == 0)
	{
		return FibArray;
	}
	FibArray[1] = 1;
	for (n = 2; n <= N; n++)
	{
		FibArray[n] = FibArray[n - 1] + FibArray[n - 2];
	}
	return FibArray;
}
int main()
{
	int i = 0;
	printf("请输入一个数:");
	scanf("%d", &i);
	long long* ret = Fibonacci(i);
	printf("该数的斐波那契数是:%d\n", ret);
	return 0;
}