#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#define MAX 100
int main()
{
	printf("%d\n", MAX);
    #undef MAX
	//printf("%d\n", MAX);
	return 0;
}

命令行定义
许多C 的编译器提供了一种能力，允许在命令行中定义符号。用于启动编译过程。 例如：当我们根据同一个源文件要
编译出不同的一个程序的不同版本的时候，这个特性有点用处。（假定某个程序中声明了一个某个长度的数组，如果
机器内存有限，我们需要一个很小的数组，但是另外一个机器内存大写，我们需要一个数组能够大写。）
gcc - D ARRAY_SIZE = 10 programe.c
int main()
{
	int arr[sz] = { 0 };
	int i = 0;
	for (i = 0; i<sz; i++)
	{
		arr[i] = i;
	}
	for (i = 0; i<sz; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}
