#include <stdio.h>
void Insert_sort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 1; i < sz;i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int tmp = 0;
			tmp = arr[i-1];
			arr[i-1] = arr[i ];
			arr[i ] = tmp;
			for ( j = i - 1; j > 0 && arr[j] < arr[j - 1]; --j)//j>0和arr[j]<arr[j-1]时循环才继续下去
			{
				int tmp = 0;
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
int main()
{
	int i = 0;
	int arr[] = { 10,29,200,100,15,9,56,78,1,5,4,3 ,8};
	int sz = sizeof(arr) / sizeof(arr[0]);
	Insert_sort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}