#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void InsertSort(int* arr, int sz)
{
	int i = 0;
	int j = 0;
	//∂‡Ã…≈≈–Ú
	for (i = 0; i < sz - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		//µ•ÃÀ≈≈–Ú
		while (end >= 0)
		{
			if (arr[end]>tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}
int main()
{
	int arr[] = { 1, 4, 5, 2, 3, 8, 7, 9, 6, 10, 6, -4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}