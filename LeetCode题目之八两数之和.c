#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int* TwoSum(int* arr, int sz, int target, int* returnsize)
{
	int* str = (int*)malloc(sizeof(int)* 2);
	*returnsize = 2;
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++)
	{
		for (j = i + 1; j < sz; j++)
		{
			if (arr[i] + arr[j] == target)
			{
				str[0] = i;
				str[1] = j;
				break;
			}
		}
	}
	return str;
}
int main()
{
	int retrunsize[] = { 0 };
	int arr[] = { 2, 7, 11, 15 };
	int target = 9;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* str = TwoSum(arr, sz, target, retrunsize);
	return 0;
}