#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<math.h>

//int binary_search(int arr[], int key, int sz) 二分查找，用函数实现
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (right + left) / 2;
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int key = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int num = binary_search(arr,key, sz);
//	if (num == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了下标是:%d\n", num);
//	}
//}

//int is_prime(int i)判断100到200之间的素数
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(i); j++)
//	{
//		if (i%j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i)==1)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//}

//int is_leap_year(int year) 1000到2000之间的闰年
//{
//	if ((year % 4 == 0 && year %400 != 0) || year % 400 == 0)
//		return 1;
//}
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (is_leap_year(year) == 1)
//		{
//			printf("%d ", year);
//		}
//	}
//	printf("\n");
//	return 0;
//}

//void swap(int *pa, int *pb)交换两个数，传址调用
//{
//	int tmp = 0;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("交换前a=%d b=%d", a, b);
//	swap(&a, &b);
//	printf("\n");
//	printf("交换后a=%d b=%d", a, b);
//	printf("\n");	
//}
//void produce_line(int i, int j)
//{
//	int a = 0;
//	int b = 0;
//	for (a = 1; a <= i; a++)
//	{
//		for (b = 1; b <= i; b++)
//		{
//			printf("%d*%d=%-2d ", a, b, a*b);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int i = 0;
//	int j=  0;
//	scanf("%d %d", &i, &j);
//	produce_line(i, j);
//	return 0;
//}

//#include<stdio.h>  求任意一年的月份
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	int leap_year = 0;
//	while ((scanf("%d %d", &year, &month) != EOF))
//	{
//		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//		{
//			day = 31;
//		}
//		else if (month == 2)
//		{
//			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//			{
//				day = 29;
//			}
//			else
//			{
//				day = 28;
//			}
//		}
//		else
//		{
//			day = 30;
//		}
//		printf("%d\n", day);
//	}
//	return 0;
//}

//#include<stdio.h>  有问题的代码
//int main()
//{
//	int i = 0;
//	int arr[7] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int min = arr[0];
//	int max = arr[sz - 1];
//	int sum = 0;
//	double average = 0.0;
//	for (i = 0; i<sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0; i<sz; i++)
//	{
//		if (min>arr[i])
//		{
//			min = arr[i];
//		}
//	}
//	for (i = 0; i<sz; i++)
//	{
//		if (max<arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	for (i = 0; i<sz; i++)
//	{
//		sum = sum + arr[i];
//	}
//	average = (sum - max - min) / 5.0;
//	printf("%.2f\n", average);
//	return 0;
//}

#include<stdio.h> 
int main()
{
	int n = 7;
	int i = 0;
	int a[7] = { 0 };
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int max = a[0];
	int min = a[0];
	for (i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	printf("%.2f", (float)(sum - max - min) / 5);

	return 0;
}