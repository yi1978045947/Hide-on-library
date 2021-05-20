#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}
	//
	int mid = left + (right - left) / 2;
	_MergeSort(arr, left, mid, tmp);     //��mid��ߵĽ��й鲢
	_MergeSort(arr, mid + 1, right, tmp);//��mid�ұߵĽ��й鲢

	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int i = left;
	while (begin1 <= end1&&begin2 <= end2)  //��������ϲ�����ֵ�ŵ�tmp�ռ���
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
	//�������������һ���Ƚ����������һ��ֱ�ӷŵ�tmp�ռ���
	while (begin1 <= end1)
	{
		tmp[i++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = arr[begin2++];
	}
	//�ϲ���֮�󣬿�����ԭ����
	for (int j = left; j <= right; j++)
	{
		arr[j] = tmp[j];
	}
}
void MergeSort(int* arr, int sz)
{
	int* tmp = (int*)malloc(sizeof(int)*sz);
	if (tmp == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	_MergeSort(arr, 0, sz - 1, tmp);
	free(tmp);
}
int main()
{
	int arr[] = { 10, 6, 7, 1, 3, 9, 4, 2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}