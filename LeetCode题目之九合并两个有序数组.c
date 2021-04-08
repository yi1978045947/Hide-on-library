#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
void merge(int arr1[], int arr2[], int sz1, int sz2)
{
	assert(arr1&&arr2);
	int end1 = sz1 - 1;
	int end2 = sz2 - 1;
	int end = sz1 + sz2 - 1;
	while (end1 >= 0 && end2 >= 0)
	{
		if (arr1[end1] > arr2[end2])
		{
			arr1[end] = arr1[end1];
			end1--;
			end--;
		}
		else
		{
			arr1[end] = arr2[end2];
			end2--;
			end--;
		}
	}
	while (end2 >= 0)
	{
		arr1[end] = arr2[end2];
		end2--;
		end--;
	}
}
int main()
{
	int arr1[] = { 1, 2, 3 };
	int arr2[] = { 4, 5, 6 };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	merge(arr1, arr2, sz1, sz2);
	int i = 0;
	for (i = 0; i < sz1+sz2; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	return 0;
}