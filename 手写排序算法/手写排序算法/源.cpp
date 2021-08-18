#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<algorithm>
using namespace std;

void InsertSort(int* arr, int sz)
{
	for (size_t i = 0; i < sz-1; i++)
	{
		int end = i;
		int tmp = arr[end+1];
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
void ShellSort(int* arr, int sz)
{
	int gap = sz;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < sz - 1; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end>=0)
			{
				if (arr[end]>tmp)
				{
					arr[end] = arr[end + 1];
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
			if (arr[i]>arr[maxIndex])
			{
				maxIndex = i;
			}
			if (arr[i] < arr[minIndex])
			{
				minIndex = i;
			}
		}
		std::swap(arr[left], arr[minIndex]);
		if (left = maxIndex)
		{
			maxIndex = minIndex;
		}
		std::swap(arr[right], arr[maxIndex]);
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

void BubbleSort(int* arr, int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] >arr[j + 1])
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


//左右指针法的快速排序
void QuickSort1(int* arr, int begin,int end)
{
	//只有一个数或者区间不存在
	if (begin >= end)
	{
		return;
	}
	//选取最左边的为key
	int key = arr[begin];
	int left = end;
	int right = end;
	while (begin < end)
	{
		while (left < right&&arr[right] >= key)
		{
			right--;
		}
		while (left < right&&arr[left] <= key)
		{
			left++;
		}
		std::swap(arr[left], arr[right]);
	}
	int meet = left;
	std::swap(key, arr[meet]);
	QuickSort1(arr, begin, meet - 1);
	QuickSort1(arr, meet, end);
}

//挖坑法
void QuicKSort2(int*arr, int begin, int end)
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
		while (left < right&&arr[right] >= key)
		{
			right--;
		}
		arr[left] = arr[right];
	}
	while (left < right)
	{
		while (left < right&&arr[left] <= key)
		{
			left++;
		}
		arr[right] = arr[left];
	}
	int meet = left;
	arr[meet] = key;
	QuicKSort2(arr, begin, meet - 1);
	QuicKSort2(arr, meet, end);
}

//前后指针法
void QuickSort3(int* arr, int begin, int end)
{

}