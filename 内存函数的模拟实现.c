#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>

//void* my_memcpy(void *arr2, const void* arr1, size_t count)
//{
//	assert(arr1&&arr2);
//	void* ret = arr2;
//	while (count--)
//	{
//		*(char*)arr2 = *(char*)arr1;
//		++(char*)arr1;
//		++(char*)arr2;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//	int arr2[30] = { 0 };
//	my_memcpy(arr2, arr1, 20);
//	return 0;
//}
void* my_memove(void* dest, const void* src, size_t count)
{
	assert(dest&&src);
	void* ret = dest;
	if (dest < src)
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	my_memove(arr + 3, arr, 20);
	return 0;
}