#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<errno.h>
//int main() //文件操作的相关问题
//{
//	//fopen函数如果是以写的形式打开
//	//如果文件不存在，会创建这个文件
//	//如果文件存在，会清空文件的内容
//	//fopen函数如果是以读的形式打开
//	//文件不存在则文件打开失败
//	FILE* pa = fopen("data.txt", "r"); //Opens for reading. If the file does not exist or cannot be found, the fopen call fails.
//	//FILE* pa = fopen("data.txt", "w"); //Opens an empty file for writing. If the given file exists, its contents are destroyed.
//	if (pa == NULL)
//	{
//		printf("文件打开失败!\n");
//		printf("%s\n", strerror(errno));
//		return 1; //失败返回
//	}	
//	else
//	{
//		int i = 0;
//		for (i = 'a'; i <= 'z'; i++)
//		{
//			fputc(i , pa);
//		}
//		printf("写入文件成功!\n");
//	}
//	             //读写文件
//	fclose(pa); //关闭文件
//	pa = NULL;
//	return 0;
//}
// 相对路径
// ../表示上一级目录
// ./当前目录
// ./文件夹//.txt 下一级路径
// ../../上上级目录

// 绝对路径 从根目录开始写的路径 D:\visua stdio 2013代码\文件操作的相关问题\文件操作的相关问题

//int main() //fgetc适合于所以输入流
//{
//	//打开文件
//	FILE* pa =fopen("data.txt", "r");
//	if (pa == NULL)
//	{
//		printf("文件打开失败!\n");
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//读取文件
//	/*int ch = fgetc(pa);
//	printf("%c\n", ch);*/
//	int ch = 0;
//	while ((ch = fgetc(pa)) != EOF)
//	{
//		printf("%c ", ch);
//	}
//	printf("\n");
//	//关闭文件
//	fclose(pa);
//	pa = NULL;
//	return 0;
//}


int main() //补充，键盘上输入
{
	int ch = 0;
	while ((ch = fgetc(stdin)) != EOF)
	{
		printf("%c\n", ch);
	}
	return 0;
}