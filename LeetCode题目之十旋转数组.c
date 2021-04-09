#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void reverse(int* arr, int left, int right)
{
	int tmp = 0;
	while (left <= right)
	{
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
void rotate(int *arr, int k, int sz)
{
	k = k%sz;
	reverse(arr, 0, sz - k - 1);
	reverse(arr, sz - k, sz - 1);
	reverse(arr, 0, sz - 1);
}
int main()
{
	int k = 0;
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("请输入要旋转几个位置:>");
	scanf("%d", &k);
	rotate(arr, k,sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}