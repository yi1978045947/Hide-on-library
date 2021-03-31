#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int FindKey(int* arr, int sz)  //“ÏªÚ
{
	int x = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		x = x^arr[i];
	}
	return x;
}
int main()
{
	int arr[] = { 1, 2, 3, 3, 2, 4, 4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = FindKey(arr, sz);
	printf("%d\n", ret);
	return 0;
}