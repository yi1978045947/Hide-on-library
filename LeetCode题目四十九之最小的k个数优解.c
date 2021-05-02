#define _CRT_SECURE_NO_WARNINGS   1
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
#include<stdio.h>
#include<stdlib.h>
void Swap(int* left, int* right)
{
	int tmp = 0;
	tmp = *left;
	*left = *right;
	*right = tmp;
}
void AdjustDown(int* a, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child<n)//(n > 0)
	{
		if (child + 1 < n&&a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
int* smallestK(int* arr, int arrSize, int k, int* returnSize)
{
	if (k == 0)
	{
		*returnSize = 0;
		return NULL;
	}
	int* arrRet = (int*)malloc(sizeof(int)*k);
	int i = 0;
	//前面k个数建立大堆
	for (i = 0; i<k; i++)
	{
		arrRet[i] = arr[i];
	}
	int j = 0;
	for (j = (k - 1 - 1) / 2; j >= 0; j--)
	{
		AdjustDown(arrRet, k, j);
	}
	//后面n-k个数，比堆顶的小，进堆，在调堆
	for (i = k; i<arrSize; i++)
	{
		if (arrRet[0]>arr[i])
			arrRet[0] = arr[i];
		AdjustDown(arrRet, k, 0);
	}
	*returnSize = k;
	return arrRet;
}
int main()
{
	return 0;
}