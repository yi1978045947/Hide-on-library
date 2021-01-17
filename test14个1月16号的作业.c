#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//int main() 三个数比大小
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a > b&&a > c&&b > c)
//	{
//		printf("%d %d %d", a, b, c);
//	}
//	else if(a > b&&a > c&& c>b )
//	{
//		printf("%d %d %d", a, c, b);
//	}
//	else if (b > c&&b > a&&a > c)
//	{
//		printf("%d %d %d", b, a, c);
//	}
//	else if (b > c&&b > a&&c > a)
//	{
//		printf("%d %d %d", b, c, a);
//	}
//	else if (c > a&&c > b&&a > b)
//	{
//		printf("%d %d %d", c, a, b);
//	}
//	else if( c>a && c>b && b>a )
//	{
//		printf("%d %d %d", c,b,a);
//	}
//	return 0;
//}

//int main()  求三个倍数
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++ )
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	return 0;
//}
//
//int main()  求最大公约数
//{
//	int i = 0;
//	int j = 0;
//	int a = 0;
//	scanf("%d %d", &i,&j);
//	a = i%j;
//	i = j;
//	j = a;
//	printf("%d\n", j);
//}

//int main()   从大到小输出三个变量
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int tmp = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b; 
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}

//int main() 求闰年
//{
//	int year = 0;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
//	printf("%d", count);
//	printf("\n");
//	return 0;
//}

//int main() 求素数
//{
//	int i = 0;
//	int n = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (n = 2; n <= i - 1; n++)
//		{
//			if (i%n == 0)
//			{
//				break;
//			}
//		}
//		if (n == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	return 0;
//}

//int main()  求1到100中9的个数
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i / 10 == 9)
//		{
//			count++;
//			printf("%d ", i);
//		}
//		if (i % 10 ==9)
//		{
//			count++;
//			printf("%d ", i);
//			printf("\n");
//		}
//	}
//	printf("count=%d\n",count);
//  return 0;
//}


//int main() 求1、1/1-1/2+1/3+....-1/100；
//{
//	int i = 0;
//	double sum1 = 0.0;
//	double sum2 = 0.0;
//	double sum3 = 0.0;
//	for (i = 1; i <= 100; i += 2)
//	{
//		sum1 = sum1 + 1.0 / i;
//	}
//	for (int i = 2; i <= 100; i += 2)
//	{
//		sum2 = sum2 + 1.0 / i;
//	}
//	sum3 = sum1 - sum2;
//	printf("sum3=%lf\n", sum3);
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int tag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum = sum + (1.0 / i)*tag;
//		tag = -tag;
//	}
//	printf("sum=%lf\n", sum);
//	return 0;
//}

//int main()  求10个数中最大值
//{ 
//	int max = 0;
//	int arr[] = { 0, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	max = arr[0];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	printf("max=%d\n", max);
//	return 0;
//}

//int main()  打印九九乘法表
//{
//	int i = 0;
//	int j = 0;
//	for ( i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d * %d=%2d ",i,j, i*j);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	return 0;
//}

int main()
{
	int i = 0;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int key = 6;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else if (arr[mid] = key)
		{
			printf("找到了，下标是%d!\n", mid);
			break;
		}
	}
	if (left>right)
	{
		printf("找不到!\n");
	}
	return 0;
}