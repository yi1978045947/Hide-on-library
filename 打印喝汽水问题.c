#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	int total = 0;
	int money = 0;
	int empty = 0;
	scanf("%d", &money);
	total = money;  //20元可以买20瓶
	empty = money; //20元就有20个空瓶
	while (empty >= 2)
	{
		total = total + empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d\n", total);
	return 0;
}