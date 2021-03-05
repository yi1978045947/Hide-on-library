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
		printf("Ð¡¶Ë\n");
	}
	else
	{
		printf("´ó¶Ë\n");
	}
	return 0;
}