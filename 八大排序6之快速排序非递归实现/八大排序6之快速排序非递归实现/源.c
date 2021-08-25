#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include"Stack.h"
void print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int QuickSort(int* arr, int left, int right)
{
	int prev = left;
	int cur = left + 1;
	int key = left;
	while (cur <= right)
	{
		if (arr[cur] < arr[key])
		{
			Swap(&arr[++prev], &arr[cur]);
		}
		cur++;
	}
	int meet = prev;
	Swap(&arr[key], &arr[prev]);
	return meet;
}
void QuickSortNonR(int* arr, int begin, int end)
{
	struct Stack st;
	StackInit(&st);
	StackPush(&st, begin); //������������
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		int left = 0;
		int right = 0;

		right = StackTop(&st); //ȡ��ֵ
		StackPop(&st);

		left = StackTop(&st); //ȡ��ֵ
		StackPop(&st);
		int key = QuickSort(arr, begin, end);
		if (left < key - 1)
		{
			StackPush(&st, left);
			StackPush(&st, key - 1);
		}
		if (key + 1 < right)
		{
			StackPush(&st, key + 1);
			StackPush(&st, right);
		}
	}
	StackDestroy(&st);
}
int main()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int begin = 0;
	int end = sz - 1;
	QuickSortNonR(arr, begin, end);
	print(arr, sz);
}