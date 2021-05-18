#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void Swap(int*a, int*b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//×óÓÒÖ¸Õë·¨
void QuickSort1(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int left = begin;
	int right = end;
	int key = left;
	while (left<right)
	{
		while (left<right && arr[right] >= arr[key])
		{
			right--;
		}
		while (left<right && arr[left] <= arr[key])
		{
			left++;
		}
		Swap(&arr[left], &arr[right]);
	}
	int meet = left;
	Swap(&arr[key], &arr[meet]);
	QuickSort1(arr, begin, meet - 1);
	QuickSort1(arr, meet + 1, end);
}
int main()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int begin = 0;
	int end = sz - 1;
	QuickSort1(arr, begin, end);
	print(arr, sz);
}