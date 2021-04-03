#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int Binary_Search(int arr[], int sz, int key)
{
	int left = 0;
	int right = sz - 1;
	int mid = 0;
	while (left <= right)
	{
		mid =  (left + right) / 2;
		if (arr[mid]>key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
			break;
		}
	}
	if (left > right)
	{
		printf("找不到!\n");
		return 0;
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int key = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = Binary_Search(arr, sz, key);
	printf("下标是:%d\n", ret);
	return 0;
}