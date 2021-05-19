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
int partSort3(int* arr, int left, int right)
{
	int prev = left;
	int cur = left + 1;
	int key = left;
	while (cur <= right)
	{
		if (arr[cur] < arr[key] )
		{
			Swap(&arr[++prev], &arr[cur]);
		}
		cur++;
	}
	int meet = prev;
	Swap(&arr[key], &arr[prev]);
	return meet;
}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	if (end - begin > 10)
	{
		int keyi = partSort3(a, begin, end);
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	else
	{
		InsertSort(a + begin, end - begin + 1);
	}

}
int main()
{
	int arr[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int begin = 0;
	int end = sz - 1;
	QuickSort(arr, begin, end);
	print(arr, sz);
}