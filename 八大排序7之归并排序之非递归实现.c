#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
void _MergeSortNonR(int* arr, int* tmp, int begin1, int end1, int begin2, int end2)
{

	int i = begin1;
	while (begin1 <= end1&&begin2 <= end2)//С�����ݷŵ�tmp�ռ�
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
	while (begin1 <= end1)//һ���ռ����������һ������ʣ�������ֱ�ӷŵ�tmp�ĺ���
	{
		tmp[i++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = arr[begin2++];
	}
	int j = begin1;
	for (j = 0; j <= end2; j++)	//������������ԭ�ռ�
	{
		arr[j] = tmp[j];
	}
		
}
void MergeSortNonR(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);//���ٸ����ռ�
	if (tmp == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	int gap = 1;//��ϲ�����������Ԫ�صĸ���
	while (gap < n)
	{
		int i = 0;
		for (i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			if (begin2 >= n)//���һ��ĵڶ���С���䲻���ڻ��ǵ�һ��С���䲻��gap������ʱ����Ҫ�Ը�С����кϲ�
			{
				break;
			}
			if (end2 >= n)//���һ��ĵڶ���С���䲻��gap������ڶ���С����ĺ���Ϊ����ĺ��
			{
				end2 = n - 1;
			}
			_MergeSortNonR(arr, tmp, begin1, end1, begin2, end2);//�ϲ�������������
		}
		gap = 2 * gap;//��һ����ϲ�����������Ԫ�صĸ�������
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