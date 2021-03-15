#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
int my_atoi(char* pa)
{
	int ret = 0; //返回值
	int sign = 1; //标志符号
	assert(pa);
	while (*pa == ' ') //跳过前面的空格字符
	{
		pa++;
	}
	if (*pa == '-')	//判断正负号
	{
		sign = -1;
	}
	if (*pa == '-' || *pa == '+') //跳过符号
	{
		pa++;
	}
	if (*pa >= '9' || *pa <= '0') //当遇到非数字字符或遇到‘ / 0’时，结束转化
	{
		return 0;
	}
	while (*pa >= '0'&&*pa <= '9') //当遇到数字字符时，把数字字符转换成整数，并把最后的整数赋值给ret
	{
		ret = ret * 10 + *pa-'0' ; //
		pa++;
	}
	ret = ret*sign;
	return ret;
}
int main()  //atoi字符串转换为整形
{
	char a[] = "-10";
	char b[] = "20";
	int c = my_atoi(a) + my_atoi(b);
	printf("a:%d\n", my_atoi(a));
	printf("b:%d\n", my_atoi(b));
	printf("a+b=%d\n", c);
	return 0;
}
//1.先处理空格
//2.正负号处理
//3.数字处理