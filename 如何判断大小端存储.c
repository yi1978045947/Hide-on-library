#define _CRT_SECURE_NO_WARNINGS   1
#include <stdio.h>
int check(int a)
{
	return *(char*)&a;
}
int main()
{
	int a = 1;
	int ret = check(a);
	if (ret == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}