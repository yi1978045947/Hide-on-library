#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<errno.h>
#include<string.h>

//int main() //fputs文本行输出流函数
//{
//	FILE* pa = fopen("data.txt", "w");
//	if (pa == NULL)
//	{
//		printf("文件打开失败!\n");
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//写一行数据
//		fputs("bit education\n", pa);
//		fputs("bit NB\n", stdout);//文本行打印到屏幕上
//		printf("文件写入成功!\n");
//	}
//	fclose(pa);
//	pa = NULL;
//	return 0;
//}

int main() //fgets适用于所有输入流
{
	char arr[100] = { 0 };
	FILE* pa = fopen("data.txt", "r");
	if (pa == NULL)
	{
		printf("打开文件失败!\n");
		printf("%s\n", strerror(errno));
		return 1;
	}
	else
	{
		//读一行数据
		//fgets(arr, 4, pa); //其中bit3个字符再包括一个\0就是4个字符，\0是字符串结束标志
		//printf("%s\n", arr);
		//printf("文件读入成功!\n");

		//读多行数据
	/*	while (fgets(arr, 4, pa) != NULL)
		{
			printf("%s", arr);
		}*/

		//也可以从屏幕上输入,标准输入流读取
		fgets(arr, 4, stdin);
		printf("%s", arr);
		printf("\n");
	}
	return 0;
}