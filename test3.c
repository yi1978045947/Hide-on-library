void bubble_sort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)            //冒泡排序的趟数
	{
		for (j = 0; j < sz - 1 - i; j++)    //冒泡排序的对数
		{
			if (arr[j] > arr[j + 1])        
			{
				int tmp = 0;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int i = 0;
	int arr[] = {100,50,30,60,80,45,12,69,28,11,0,1,2,4};
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}