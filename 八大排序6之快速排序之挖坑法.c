#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//�ڿӷ�
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
		while (left<right && arr[right] >= key)
		{
			right--;
		}
		//��ֵ�ŵ���ߵĿ�λ
		arr[left] = arr[right];
		while (left<right && arr[left] <= key)
		{
			left++;
		}
		//��ֵ�ŵ��ұߵĿ�λ
		arr[right] = arr[left];
	}
	int meet = left;
	//���������λ�þ��ǿ�λ
	arr[meet] = key;
	QuickSort2(arr, begin, key - 1);
	QuickSort2(arr, key + 1, end);
}
int main()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int begin = 0;
	int end = sz - 1;
	QuickSort2(arr, begin, end);
	print(arr, sz);
}