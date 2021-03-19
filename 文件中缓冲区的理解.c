#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<Windows.h>
int main()  //输入缓冲区的理解
{
	FILE* pa = fopen("data.txt", "w");  //打开文件
	if (pa == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else                                //写进文件
	{
		fputs("abcde", pa);
		printf("睡眠10s,写进缓冲区的数据!\n");
		Sleep(10000);
		fflush(pa);  //注意fflush在vs高的版本不能使用
		printf("在睡眠10s,此时打开data.txt文档，就有数据!\n");
		Sleep(10000);
	}
		fclose(pa);
		pa = NULL;                 //关闭文件
	return 0;
}