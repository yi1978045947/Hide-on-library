#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int check_key()
{
	union un
	{
		char c;
		int a;
	};
	union un u;
	u.a = 1;
	return u.c;
}
int main()
{
	int ret = check_key();
	if (ret == 1)
	{
		printf("С��!\n");
	}
	else
	{
		printf("���!\n");
	}
	return 0;
}