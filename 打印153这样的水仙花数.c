#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<math.h>
//判断i是否为水仙花数
//1.先判断i为几位数
//2.计算i的每一位的次方和
//3.判断
int main()
{
	int i = 0;
	for (i = 10; i <= 100000; i++)
	{
		int tmp = 1;
		int sum = 0;
		int count = 1; //记录该数为几位数
		tmp = i;
		//1.判断数有几位
		while (tmp/10)
		{
			count++;
			tmp = tmp / 10;
		}
		//2.计算该数的次方和
		tmp = i; //tmp判断好有几位数但是tmp的值不能改变,所以重新把i值赋值给tmp;
		while (tmp)
		{
			sum = sum + pow(tmp % 10, count);
			tmp = tmp / 10;
		}
		//3.判断此时i是否等于sum来判断该数是否为水仙花数
		if (sum == i)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}