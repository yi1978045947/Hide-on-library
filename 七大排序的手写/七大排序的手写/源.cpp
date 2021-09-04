#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<algorithm>
using namespace std;

void InsertSort(int* arr, int sz)
{
	for (size_t i = 0; i < sz - 1; i++)
	{
		int end = i;
		int tmp = arr[end + i];
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
		arr[end + i] = tmp;
	}
}

void ShellSort(int* arr, int sz)
{
	int gap = sz;
	while (gap > 1)
	{
		gap = sz / 3 + 1;
		for (size_t i = 0; i < sz - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end]>tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}

void SelectSort(int* arr, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int minIndex = left;
		int maxIndex = left;
		for (size_t i = left; i <= right; i++)
		{
			if (arr[i] < minIndex)
			{
				minIndex = i;
			}
			if (arr[i]>maxIndex)
			{
				maxIndex = i;
			}
		}
		std::swap(arr[left], arr[minIndex]);
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}
		std::swap(arr[right], arr[maxIndex]);
		left++;
		right--;
	}
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
	for (size_t i = (sz - 1 - 1) / 2; i >= 0; i--)
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

void BubbleSort(int* arr, int sz)
{
	for (size_t i = 0; i < sz - 1; i++)
	{
		int flag = 0;
		for (size_t j = 0; i < sz - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				flag = 1;
			}
			if (flag == 0)
			{
				break;
			}
		}
	}
}

void QuickSort1(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	int key = arr[begin];
	int left = begin;
	int right = end;

	while (left < right)
	{
		while (left<right&&arr[right]>=key)
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
	int left = begin;
	int right = end;
	int key = arr[begin];

	while (left < right)
	{
		while (left<right&&arr[right]>key)
		{
			right--;
		}
		std::swap(arr[left], arr[right]);
		while (left < right&&arr[left] < key)
		{
			left++;
		}
		std::swap(arr[right], arr[left]);
	}
	int meet = left;
	arr[meet] = key;
	QuickSort2(arr, begin, meet - 1);
	QuickSort2(arr, meet + 1, end);
}

void MergeSort(int* arr, int left, int right, int* tmp)
{
	int mid = left + (right - left);
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

	for (size_t j = left; j <= right; j++)
	{
		arr[j] = tmp[j];
	}
}