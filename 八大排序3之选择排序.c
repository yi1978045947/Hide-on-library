#define _CRT_SECURE_NO_WARNINGS   1
#include <stdio.h>
void Swap(int *a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SelectSort(int* arr, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int minIndex = left;
		int maxIndex = left;
		for (int i = left; i <= right; i++)
		{
			if (arr[i] < arr[minIndex])
			{
				minIndex = i;
			}
			if (arr[i]>arr[maxIndex])
			{
				maxIndex = i;
			}
		}
		Swap(&arr[left], &arr[minIndex]);
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}
		Swap(&arr[right], &arr[maxIndex]);
		left++;
		right--;
	}
}
int main()
{
	int arr[] = { 7, 4, 5, 9, 8, 2, 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}