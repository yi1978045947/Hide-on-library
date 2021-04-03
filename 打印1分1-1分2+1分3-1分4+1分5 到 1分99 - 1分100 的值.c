#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	int i = 0;
	int flag = 1;
	double sum = 0.0;
	for (i = 1; i <= 100; i++)
	{
		sum = sum + (1.0 / i)*flag;//注意使用操作费/要得到小数位结果必须除数和被除数有一位是小数
		flag = -flag;
	}
	printf("%lf\n", sum);
	return 0;
}