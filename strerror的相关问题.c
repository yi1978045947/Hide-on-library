#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<errno.h>
int main() //strerror错误报告函数,库函数发生错误
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		perror(""); //相比strerror函数，perror封装了这些信息
	}
	return 0;
}