#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int Find_Key(int arr[], int key, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		if ((key&arr[i]) == key)
		{
			break;
		}
	}
	return key;
}
int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int key = 5;
	int ret = 0;
	ret = Find_Key(arr, key,sz);
	printf("%d\n", ret);
	return 0;
}