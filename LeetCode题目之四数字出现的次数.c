#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<malloc.h>
//1.先把所有的数字异或，相同数异或为0，不同数就可以异或得到一个结果
//2.找到这个结果的j位为1
//3.把j位为1的分为a组，j位为b的分为b组，那么两个数就会分到不同的组，相同的数在a组或b组
//4.再对a，b组的进行异或，相同数则被异或掉，剩下的就是要找的数
int* signalNumbers(int* arr, int sz, int* returnsize)
{
	int x = 0;
	int y = 0;
	int ret = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		ret = ret^arr[i];
	}
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		if ((ret >> j) & 1)
		{
			break;
		}
	}
	int k = 0;
	for (k = 0; k < sz; k++)
	{
		if ((arr[k] >> j) & 1)  //为1的放到a组
		{
			x = x^arr[k];
		}
		else                   //为0的放到b组
		{
			y = y^arr[k];
		}
	}
	int* str = (int*)malloc(sizeof(int)* 2);
	str[0] = x;
	str[1] = y;
	*returnsize = 2;
	return str;
}
