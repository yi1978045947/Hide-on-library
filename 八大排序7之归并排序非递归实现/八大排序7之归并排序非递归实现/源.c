#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
void _MergeSortNonR(int* arr, int* tmp, int begin1, int end1, int begin2, int end2)
{

	int i = begin1;
	while (begin1 <= end1&&begin2 <= end2)//小的数据放到tmp空间
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
	while (begin1 <= end1)//一个空间结束，将另一个区间剩余的数据直接放到tmp的后面
	{
		tmp[i++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = arr[begin2++];
	}
	int j = begin1;
	for (j = 0; j <= end2; j++)	//结束，拷贝回原空间
	{
		arr[j] = tmp[j];
	}
		
}
void MergeSortNonR(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);//开辟辅助空间
	if (tmp == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	int gap = 1;//需合并的子序列中元素的个数
	while (gap < n)
	{
		int i = 0;
		for (i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			if (begin2 >= n)//最后一组的第二个小区间不存在或是第一个小区间不够gap个，此时不需要对该小组进行合并
			{
				break;
			}
			if (end2 >= n)//最后一组的第二个小区间不够gap个，则第二个小区间的后界变为数组的后界
			{
				end2 = n - 1;
			}
			_MergeSortNonR(arr, tmp, begin1, end1, begin2, end2);//合并两个有序序列
		}
		gap = 2 * gap;//下一趟需合并的子序列中元素的个数翻倍
	}
	free(tmp);
}
int main()
{
	int arr[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	MergeSortNonR(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}