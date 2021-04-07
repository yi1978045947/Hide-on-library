#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int FindDiff(int i, int j)
{
	int ret = 0;
	int count = 0;
	ret = i^j; //根据异或相同为1，不同为0 来计算
	int a = 0;
	for (a = 0; a < 32; a++)
	{
		if ((ret >> a) & 1 == 1)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int i = 0;
	int j = 0;
	scanf("%d%d", &i, &j);
	int ret = FindDiff(i, j);
	printf("%d\n", ret);
	return 0;
}

#include <stdio.h>

int get_differ(int i, int j)
{
	int count = 0;
	int tmp = 0;
	tmp = i^j;
	while (tmp)
	{
		tmp = tmp&(tmp - 1);
		count++;
	}
	return count;
}
int main()
{
	int i = 0;
	int j = 0;
	int count = 0;
	scanf("%d%d", &i, &j);
	count = get_differ(i, j);
	printf("%d\n", count);
}