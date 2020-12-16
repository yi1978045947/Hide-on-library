#include <stdio.h>

int FindMid(int arr[], int low, int high)
{
	int pk = arr[low];   //½èÖú¸¨Öú0¿Õ¼ä´æÈ¡Ç÷Öá¹Ø¼ü×Ö
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
		Quick_Sort(arr, low, memory - 1);  //±éÀúÑ°ÕÒmemory×ó±ßµÄÇ÷Öá¹Ø¼ü×Ö
		Quick_Sort(arr, memory + 1, high); //±éÀúÑ°ÕÒmemoryÓÒ±ßµÄÇ÷Öá¹Ø¼ü×Ö
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