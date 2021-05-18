#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void BubbleSort(int* arr, int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int exchange = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
				exchange = 1;
			}
			if (exchange = 0)
			{
				break;
			}
		}
	}
}
int main()
{
	int arr[] = { 6, 25, 24, 9, 12, 55, 56 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}