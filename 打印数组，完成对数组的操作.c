#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void reverse(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int tmp = 0;
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void Init(int arr[], int sz)
{
	int i = 0;
	for( i = 0; i < sz;i++)
	{
		arr[i] = 0;
	}
}
int main()
{
	int i = 0;
	int arr[] = { 10, 9, 4, 3, 5, 6, 7, 8, 2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Init(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	print(arr, sz);
	reverse(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}