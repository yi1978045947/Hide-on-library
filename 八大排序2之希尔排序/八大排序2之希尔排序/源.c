#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void ShellSort(int* arr, int sz)
{
	//gap>1的时候，预排序
	//gap=1的时候，直接插入排序
	int gap = sz;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < sz - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end]>tmp)
				{
					arr[end + gap] = arr[end];
					end = end - gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
		printf("gap=%d ", gap);
		for (int i = 0; i < sz; i++)
		{
			printf("%d-->", arr[i]);
		}
		printf("NULL\n");
	}

}
int main()
{
	int arr[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}