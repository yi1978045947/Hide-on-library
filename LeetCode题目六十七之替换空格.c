#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* replaceSpace(char* s)
{
	int length = strlen(s);
	char* res = (char*)malloc(sizeof(char)* 3 * length + 1);
	int i = 0;
	int count = 0;
	for (i = 0; i < length; i++)
	{
		if (s[i] == ' ')
		{
			res[count++] = '%';
			res[count++] = '2';
			res[count++] = '0';
		}
		else
		{
			res[count++] = s[i];
		}
	}
	res[count] = '\0';
	return res;
}
int main()
{
	return 0;
}