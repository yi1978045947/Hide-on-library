#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<Windows.h>
void walk(int arr1[], int arr2[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		Sleep(1000);
		arr1[left] = arr2[left];
		arr1[right] = arr2[right];
		left++;
		right--;
		printf("%s\n", arr1);
	}
}
int main()
{
	char arr1[] = "*********************";
	char arr2[] = "bit  <-> education!..";
	int sz = strlen(arr2);
	walk(arr1, arr2, sz);
	return 0;
}