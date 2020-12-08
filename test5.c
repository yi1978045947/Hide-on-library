#include<stdio.h>

void BInsert_sort(int arr[], int sz)
{
	for ( int i = 2; i <sz; i++) //下标为0的作为哨兵不放数据
	{
		arr[0] = arr[i];
		int left = 1;
		int right = i - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (arr[0] >= arr[mid])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		for (int j = i; j >= right + 1; --j)
		{
			arr[ j ] = arr[ j-1 ]; 
		}
		arr[right + 1] = arr[0];
	}
}

int main()
{
	int arr[] = { 0,40,20,1,15,2,6,7,90,16,12,55,35 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	BInsert_sort(arr, sz);
	for (int i = 1; i <sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}