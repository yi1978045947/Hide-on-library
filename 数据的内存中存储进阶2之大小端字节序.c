#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int FindKey(int i)
{
	return *(char*)&i;
}
int main()
{
	int i = 1;
	int ret = FindKey(i);
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