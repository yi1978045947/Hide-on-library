#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int FindDiff(int arr[], int sz)
{
	int i = 0;
	int x = 0;
	for (i=0; i < sz; i++)
	{
		x = x^arr[i];
	}
	return x;
}
int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 4, 4, 5, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = FindDiff(arr, sz);
	printf("%d\n", ret);
	return 0;
}