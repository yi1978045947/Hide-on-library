#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void Bubble_Sort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	int flag = 1;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = 0;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}
int main()
{
	int i = 0;
	int arr[] = { 1, 3, 4, 5, 6, 7, 8, -1, 2, -3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_Sort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}