#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}
int singleNumber(int arr[], int sz)
{
	qsort(arr, sz, sizeof(int), cmp_int);
	int i = 0;
	if (sz == 1)
	{
		return arr[0];
	}
	if (arr[0] != arr[1])
	{
		return arr[0];
	}
	if (arr[i - 1] != arr[i - 2])
	{
		return arr[i - 1];
	}
	for (i = 3; i < sz - 2; i += 3)
	{
		if (arr[i] != arr[i + 1] && arr[i] != arr[i - 1])
		{
			return arr[i];
		}
	}
	return 0;
}
int main()
{
	int arr[]={1, 1, 1, 3, 3, 3,4,5,5, 5, 6, 6, 6};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = singleNumber(arr, sz);
	printf("%d\n", ret);
	return 0;
}