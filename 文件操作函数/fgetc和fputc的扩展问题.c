#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char arr[100];
	FILE* pa = fopen("test.txt", "w");//"a"  aÊÇ×·¼Ó
	if (pa == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		while (1)
		{
			gets(arr);
			if (strcmp(arr, "exit") == 0)
			{
				break;
			}
			else
			{
				fputs(arr, pa);
				fputc('\n',pa);
			}
		}
	}
	fclose(pa);
	return 0;
}