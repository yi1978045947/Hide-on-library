#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
void ReplaceSpace(char* str, int length)
{
	int i = 0;
	int spacecount = 0;
	for (i = 0; i < length; i++) //1.统计空格个数
	{
		if (str[i] == ' ')
		{
			spacecount++;
		}
	}
	int newlen = length + 2 * spacecount; //2.算出替换了%20后字符串新的长度的最后位置
	int pos = newlen - 1;  //计算最后一个字符的下标
	for (i = length - 1; i >= 0; i--) //3.从后往前处理空格
	{
		if (str[i] == ' ')
		{
			str[pos--] = '0';
			str[pos--] = '2';
			str[pos--] = '%';
		}
		else //不是空格就在原来字符重新拷贝过去到arr的后面
		{
			str[pos--] = str[i];
		}
	}
}
int main()
{
	char arr[1024] = "we are happy.";
	int len = strlen(arr);
	ReplaceSpace(arr, len);
	printf("%s\n", arr);
	return 0;
}