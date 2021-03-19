#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<errno.h>
int main() //fseek的相关问题，根据文件指针的位置和偏移量来定位文件指针。
{
	FILE* pa = fopen("data.txt", "r");
	if (pa == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int ch = 0;

		/*ch = fgetc(pa);
		printf("%c\n", ch);
		ch = fgetc(pa);
		printf("%c\n", ch); */

		//fseek根据文件指针的位置和偏移量来定位文件指针。
		//fseek(pa,0, SEEK_CUR);//流，SEEK_CUR文件当前位置 ，起始位置偏移两个字节
		//fseek(pa,0, SEEK_SET); //流，SEEK_SET文件起始位置，起始位置就是a
		//fseek(pa, -3, SEEK_END); //流，SEEK_END文件结束标志，结束标志是\0，所以当offset为0 时，读取到的是\0
		/*ch = fgetc(pa);
		printf("%c\n", ch);*/

		//rewind(pa); //rewind让文件指针的位置回到文件的起始位置

		//printf("%d\n", ftell(pa)); //ftell返回文件指针相对于起始位置的偏移量
		//printf("%c\n", ch);
		while ((ch = fgetc(pa)) != EOF)
		{
			printf("%c ", ch);
		}
		printf("\n");
		if (ferror(pa))
		{
			printf("读取时发生错误，失败而结束!\n");
		}
		else if (feof(pa))
		{
			printf("遇到文件末尾结束!\n");
		}
	}
	fclose(pa);
	pa = NULL;
	
	//当我们使用fgetc读取的时候,1.发生错误结束了 2.读取到文件末尾结束了 EOF结束
	//当我们使用fgets读取的时候 1.发生错误结束啦 2.读取到文件末尾结束了 NULL结束
	//当我们使用fread发现实际读取的个数小于要求读取的最大个数 例如要求读取5个，实际读取4个就结束了
	return 0;

	/*  文件结束判定
		被错误使用的 feof
		牢记：在文件读取过程中，不能用feof函数的返回值直接用来判断文件的是否结束。
		而是应用于当文件读取结束的时候，判断是读取失败结束，还是遇到文件尾结束。
		1. 文本文件读取是否结束，判断返回值是否为EOF （fgetc），或者NULL（fgets）
		例如：
		fgetc判断是否为EOF.
		fgets判断返回值是否为NULL.
		2. 二进制文件的读取结束判断，判断返回值是否小于实际要读的个数。
		例如：
		fread判断返回值是否小于实际要读的个数。*/
}