#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<malloc.h>
//1.�Ȱ����е����������ͬ�����Ϊ0����ͬ���Ϳ������õ�һ�����
//2.�ҵ���������jλΪ1
//3.��jλΪ1�ķ�Ϊa�飬jλΪb�ķ�Ϊb�飬��ô�������ͻ�ֵ���ͬ���飬��ͬ������a���b��
//4.�ٶ�a��b��Ľ��������ͬ����������ʣ�µľ���Ҫ�ҵ���
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
		if ((arr[k] >> j) & 1)  //Ϊ1�ķŵ�a��
		{
			x = x^arr[k];
		}
		else                   //Ϊ0�ķŵ�b��
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
