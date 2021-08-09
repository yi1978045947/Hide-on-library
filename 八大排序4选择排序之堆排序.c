#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void swap(int* left, int* right)
{
	int tmp = 0;
	tmp = *left;
	*left = *right;
	*right = tmp;
}
void AdjustDown(int* arr, int sz, int parent)
{
	int child = 2 * parent + 1;
	while (child < sz)
	{
		if (child + 1 < sz&&arr[child + 1] > arr[child])
		{
			child++;
		}
		if (arr[child]>arr[parent])
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
//排升序，建大堆
void HeapSort(int *arr, int sz)
{
	//建堆
	int i = (sz - 1 - 1) / 2;
	for (i = (sz - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, sz, i);
	}
	int end = sz - 1;	
	while (end > 0)
	{
		//选出次大的
		swap(&arr[0], &arr[end]);
		//最后一个不用交换，所以为n-1个数为end
		AdjustDown(arr, end, 0);
		end--;
	}
}
int main()
{
	int arr[] = { 15, 18, 28, 34, 65, 19, 49, 25, 37, 27, -1, -10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}