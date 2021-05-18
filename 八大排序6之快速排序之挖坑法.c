#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//挖坑法
void QuickSort2(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int left = begin;
	int right = end;
	int key = arr[begin];
	while (left < right)
	{
		while (left<right && arr[right] >= key)
		{
			right--;
		}
		//把值放到左边的坑位
		arr[left] = arr[right];
		while (left<right && arr[left] <= key)
		{
			left++;
		}
		//把值放到右边的坑位
		arr[right] = arr[left];
	}
	int meet = left;
	//最后相遇的位置就是坑位
	arr[meet] = key;
	QuickSort2(arr, begin, key - 1);
	QuickSort2(arr, key + 1, end);
}
int main()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int begin = 0;
	int end = sz - 1;
	QuickSort2(arr, begin, end);
	print(arr, sz);
}