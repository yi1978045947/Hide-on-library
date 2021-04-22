#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}
int findDuplicate(int arr[], int sz)
{
	qsort(arr, sz, sizeof(int), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			return arr[i];
		}
	}
	return -1;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 2, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = findDuplicate(arr, sz);
	printf("%d\n", i);
	return 0;
}