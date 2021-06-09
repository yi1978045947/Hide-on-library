#include <stdio.h>
#include <string.h>
const int MAX = 16 * 100;
int main(void)
{
	//获取、输出字符串
	char str[MAX];
	gets(str);
	puts(str);

	int MaxLine = (int)strlen(str) / 16;//总行数
	int MaxLen = strlen(str);

	int i = 1;//控制输出行数
	int j = 0;//控制输出字符
	int k = 0;//控制输出字符串

	for (; i <= MaxLine; i++)
 	{
		//第一部分
   	//printf("%08x  ", 16 * (i - 1));
		//第二部分*/
		for (; j < MaxLen; j++) 
        {
			printf("0x%x ", str[j]);
			if (j == 16 * i - 1)
            {
				j += 1;
				break;
			}
		}
		printf("  ");
		//第三部分
		for (; k <= j - 1; k++) 
        {
			printf("%c", str[k]);
		}
		printf("\n");
	}
	return 0;
}
