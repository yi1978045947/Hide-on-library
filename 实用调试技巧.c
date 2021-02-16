#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
//int my_strlen(char arr[])
//{
//	int count = 0;
//	assert(arr);
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//int main()
//{
//	int len = 0;
//	char arr[] = "abcdef";
//	len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}
//

//void move(int arr[],int sz)  输入整数，交换顺序，偶数在前，奇数在后
//{
//	int tmp = 0;
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		while ( (left<right) && arr[left] % 2 == 1)
//		{
//			left++;
//		}
//		while ( (left<right) && arr[right] % 2 == 0)
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//}
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr,sz);
//	print(arr,sz);
//	return 0;
//}

void strcpy(char *arr1,const char *arr2)
{
	assert(arr1);
	assert(arr2);
	while (*arr2 != '\0')
	{
		*arr1 = *arr2;
		arr1++;
		arr2++;
	}
}
int main()
{
	char arr1[] = "******************";
	char arr2[] = "BitEducation";
	strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}