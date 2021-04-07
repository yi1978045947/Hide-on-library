#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr[10];
	scanf("%d", &arr);
	int* pq = &arr;
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(pq + i));
	}
	printf("\n");
	return 0;
}