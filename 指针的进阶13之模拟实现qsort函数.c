#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int cmp_int(const void* e1, const void* e2)
{
	return (*(char*)e1 - *(char*)e2);
}
void _swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp =*buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void Bubble_Sort(void* base, int num, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < num - 1; i++)
	{
		int j = 0;
		for (j = 0; j < num - 1 - i; j++)
		{
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
			{
				_swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}
int main()
{
	int i = 0;
	int arr[] = { 3, 2, 5, 7, 4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_Sort(arr, sz, sizeof(arr[0]), cmp_int);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}