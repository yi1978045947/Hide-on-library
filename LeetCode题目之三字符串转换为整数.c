#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
int change(char* str)
{
	assert(str);
	int signal = 1;
	int ret = 0;
	while (*str == ' ')
	{
		str++;
	}
	if (*str == '-')
	{
		signal = -1;
	}
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	if (*str <'0'||*str>'9' )
	{
		return 0;
	}
	while (*str >= '0'&&*str <= '9')
	{
		ret = ret * 10 + *str - '0';
		str++;
	}
	ret = ret*signal;
	return ret;
}
int main()
{
	char a[] = "-30";
	char b[] = "20";
	int ret = change(a) + change(b);
	printf("%d\n", ret);
	return 0;
}
//1.先处理空格
//2.判断是否为正负号
//3.正负号处理
//4.字符数字转换为整形数字处理
