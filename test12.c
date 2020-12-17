#include <stdio.h>

int Select_MinKey(int arr[], int k, int sz) // k为趟数，sz为元素个数！
{
	int minval = arr[k];
	int pos = k;
	for (int i = k + 1; i < sz; i++)
	{
		if (arr[i] < minval)
		{
			minval = arr[i];
			pos = i;
		}
	}
	return pos;
}

void Select_Sort(int arr[], int sz)
{
	int i = 0;
	for (i = 1; i < sz; i++)
	{
		int j = Select_MinKey(arr, i, sz);
		if (j != i)
		{
			int tmp = 0;
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}
}

int main()
{
	int i = 0;
	int arr[] = { 0,49,38,4594,32,43,123,12,3,3,5,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Select_Sort(arr, sz);
	for(i = 0; i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}