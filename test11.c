#include <stdio.h>

int FindMid(int arr[], int low, int high)
{
	int pk = arr[low];   //��������0�ռ��ȡ����ؼ���
	while (low < high)
	{
		while (low < high && arr[high] >= pk)
		{
			high--;
		}
		arr[low] = arr[high];
		while (low < high && arr[low] < pk)
		{
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = pk;
	return low;
}

void Quick_Sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int memory = FindMid(arr, low, high);
		Quick_Sort(arr, low, memory - 1);  //����Ѱ��memory��ߵ�����ؼ���
		Quick_Sort(arr, memory + 1, high); //����Ѱ��memory�ұߵ�����ؼ���
	}
}

int  main()
{
	int i = 0;
	int arr[] = { 0,49,23,4,78,56,32,13,21,35,49 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int low = 0;
	int high = sz - 1;
	Quick_Sort(arr, low, high);
	for (i = 1; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}