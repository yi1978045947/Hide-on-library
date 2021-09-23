#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<algorithm>
void AdjustDown(int* arr, int sz, int parent)
{
	int child = 2 * parent + 1;
	while (child < sz)
	{
		if (child + 1 < sz&&arr[child + 1] > arr[child])
		{
			child++;
		}
		if (arr[child]>parent)
		{
			std::swap(arr[child], arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int sz)  
{
	for (int i = (sz - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, sz, i);
	}
	int end = sz - 1;
	while (end > 0)
	{
		std::swap(arr[0], arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
}

void QuickSort1(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return ;
	}
	int key = arr[begin];
	int left = begin;
	int right = end;

	while (left < right)
	{
		while (left < right&&arr[right] >= key)
		{
			right--;
		}
		while (left < right&&arr[left] >= key)
		{
			left++;
		}
		std::swap(arr[left], arr[right]);
	}
	int meet = left;
	std::swap(key, arr[left]);
	QuickSort1(arr, begin, meet - 1);
	QuickSort1(arr, meet + 1, end);
}
void QuickSort2(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	int key = arr[begin];
	int left = begin;
	int right = begin;
	while (left < right)
	{
		while (left < right&&arr[right] >= key)
		{
			right--;
		}
		arr[left] = arr[right];//把值放到左边的坑中
		while (left < right&&arr[left] <= key)
		{
			left++;
		}
		arr[right] = arr[left];
	}
	int meet = left;
	arr[meet] = key;
	QuickSort2(arr, begin, meet - 1);
	QuickSort2(arr, meet + 1, end);
}

void MergeSort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return ;
	}
	int mid = left + (right - left) / 2;
	MergeSort(arr, left, mid, tmp);
	MergeSort(arr, mid + 1, right, tmp);

	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;

	int i = left;

	while (begin1 <= end1&&begin2 <= end2)
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
	while (begin1 <= end1)
	{
		tmp[i++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = arr[begin2++];
	}

	for (int j = left; j <= right; j++) //拷贝会原空间
	{
		arr[j] = tmp[j];
	}
}