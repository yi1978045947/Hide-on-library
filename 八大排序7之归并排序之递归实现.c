#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}
	//
	int mid = left + (right - left) / 2;
	_MergeSort(arr, left, mid, tmp);     //对mid左边的进行归并
	_MergeSort(arr, mid + 1, right, tmp);//对mid右边的进行归并

	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int i = left;
	while (begin1 <= end1&&begin2 <= end2)  //两端区间合并，将值放到tmp空间中
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[i++] = arr[begin1++];
		}
		else
		{
			tmp[i++] = arr[begin2++];
		}
	}
	//如果左右区间中一个先结束，则把另一个直接放到tmp空间中
	while (begin1 <= end1)
	{
		tmp[i++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = arr[begin2++];
	}
	//合并完之后，拷贝回原数组
	for (int j = left; j <= right; j++)
	{
		arr[j] = tmp[j];
	}
}
void MergeSort(int* arr, int sz)
{
	int* tmp = (int*)malloc(sizeof(int)*sz);
	if (tmp == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	_MergeSort(arr, 0, sz - 1, tmp);
	free(tmp);
}
int main()
{
	int arr[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}