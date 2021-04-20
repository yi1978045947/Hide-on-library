#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
void* my_memset(const void* arr, int c, int count)
{
	assert(arr);
	char* ret = (char*)arr;
	while (count--)
	{
		*(char*)arr = c;
		((char*)arr)++;
	}
	return ret;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	my_memset(arr, 0, sizeof(int)* 6);
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
