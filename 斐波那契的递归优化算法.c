#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int Fib(int n,int first,int second)  //尾递归方法通过两个变量保存计算值，传递给下一次进行计算，\
                                     递归的过程中也是根据n值变化逐步重复运算，和循环差不多，\
                                      时间复杂度和空间复杂度也都一样，但是比循环更简洁，更优雅
{
	if (n <= 1)
	{
		return first;
	}
	else
	{
		return Fib(n - 1, second, first + second);
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int first = 1;
	int second = 1;
	int ret = Fib(n, first, second);
	printf("%d\n", ret);
	return 0;
}