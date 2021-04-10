#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void swap(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		//��ǰ�����ң��ҵ�ż��ֹͣ
		while ((left < right)&&arr[left] % 2 == 1)
		{
			left++;
		}
		//�Ӻ���ǰ�ң��ҵ�����ֹͣ
		while ((left < right) && arr[right] % 2 == 0)
		{
			right--;
		}
		//�����ҵ���������ż��
		if (left < right)
		{
			int tmp = 0;
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	swap(arr,sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}