#include <stdio.h>
void ShellInsert(int arr[], int sz1, int dk)
{
	int i ;
	int j ;
	for (i = dk + 1; i < sz1; i++)
	{
		if (arr[i] < arr[i - dk])
		{
			arr[0]= arr[i];               //把要比较的i值存入辅助空间--下标为0的空间
			for ( j = i - dk; j > 0 && arr[0] < arr[j]; j = j - dk)
			{
				arr[j + dk] = arr[j];
			}
			arr[j + dk] = arr[0];
		}
	}
}
void ShellSort(int arr[], int sz1, int add[], int sz2)
{
	int k = 0;
	for ( k = 0; k < sz2; k++)
	{
		ShellInsert(arr, sz1, add[k]);
	}
}

int main()
{
	int arr[] = {0,5,13,23,49,55,4,49,38,65,97,76 };
	int sz1 = sizeof(arr) / sizeof(arr[0]);
	int add[] = { 5,3,2,1 };
	int sz2 = sizeof(add) / sizeof(add[0]);
	ShellSort(arr, sz1, add, sz2);
	int i;
	for ( i = 1; i < sz1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}