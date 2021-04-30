#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void swap(int* child, int* parent)
{
	int tmp = 0;
	tmp = *child;
	*child = *parent;
	*parent = tmp;
}
void AdjustDown(int* arr, int sz, int parent)
{
	int child = 2 * parent + 1;
	while (child < sz)
	{
		if (child+1<sz && arr[child + 1]<arr[child])
		{
			child++;
		}
		if (arr[child] < arr[parent])
		{
			swap(&arr[child], &arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
int main()
{
	int arr[] = { 27, 15, 29, 18, 28, 34, 65, 49, 25, 37 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	AdjustDown(arr, sz, 0);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}