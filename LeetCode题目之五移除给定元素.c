#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int RemoveElement(int *arr, int sz, int val)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++)
	{
		if (arr[i] != val)
		{
			arr[j] = arr[i];
			j++;
		}
	}
	return j;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 4, 5, 6, 6, 4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int val = 4;
	int ret = RemoveElement(arr, sz, val);
	printf("%d\n", ret);
	return 0;
}