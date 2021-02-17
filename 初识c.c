#include <stdio.h>
/* int main()
{
	printf("你好。\n");
	return 0;
}*/
/*int main()
{
	char ch = 'a';
	printf("%c",ch);
	return 0;
}*/
/*int main()
{
	int age = 20;
	printf("%d", age);
	return 0;
}*/
/*int main() 
{
	int sum = 0;
	int sum1 = 0;
	int sum2 = 0;
	scanf("%d%d", &sum1,&sum2);
	sum = sum1 + sum2;
	printf("sum=%d", sum);
	return 0;
}*/
#include <string.h>
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = {'a','b','c','\0'};
//	printf("%d\n", strlen(arr1));
//	printf("%d\n", strlen(arr2));
//	return 0;
//}
//int main()
//{
//	int select = 1;
//	printf("学校的生活。\n");
//	printf("请输入你的选择(0/1):>");
//	scanf("%d", &select);
//	if (select == 0)
//	{
//		printf("好好学习。");
//	}
//	else 
//		printf("回家种地。");
//	
//}
//int main()
//{
//	int money = 0;
//	printf("我的人生\n");
//	while (money <=10000000)
//	{
//		printf("努力赚钱%d块\n",money);
//		money++;
//	}
//	if (money > 10000000)
//	{
//		printf("迎娶白富美");
//	}
//	return 0;
//}
//int add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//int main()
//{
//	int sum = 0;
//	sum = add(2, 3);
//	printf("sum=%d", sum);
//	return 0;
//}
//int main()
//{
//	int arr[6] = { 1,2,3,4,5,6 };
//	int i = 0;
//	while (i <6)
//	{
//		printf("%d", arr[i]);
//		i++;
//	}
//	return 0;
//}
//int main()
//{
//	int b;
//	int a = 1;
//	 b = a << 1;
//	printf("%d", b);
//	return 0;
//}
//int main()
//{
//	int a = 2; int b = 4;
//	int c = a^b;
//	printf("%d", c);
//}
//int max(x, y)
//{
//	
//}
//int max(x, y)
//{
//	int z;
//	if (x > y)
//		z = x;
//	else
//		z = y;
//}
//int main()
//{
//	int sum = 0;
//	int num1 = 10;
//	int num2 = 20;
//	sum=max(num1, num2);
//	printf("最大值为%d",sum);
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = ~a;
//	printf("%d", b);
//	return 0;
//}

//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int key =20;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	int left = 0;
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
//		{
//			printf("查找的数已找到，下标是%d", mid);
//			break;
//		}
//	}
//		if(left>right)
//		{
//			printf("该数找不到!\n");
//		}
//		return 0;
//}


//int is_leap_year(int x)
//{
//	if (x%4 == 0 && x%100 != 0)
//	{
//		return 1;
//	}
//	else if (x%400 == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int year = 0;
//	for(int year=1000;year<=2000;year++)
//	{
//		if(is_leap_year(year)==1)
//		{
//			printf("%d\n", year);
//		}
//	}
//}
//int is_prime(int x)
//{
//	for (int j = 2; j < x; j++)
//	{
//		if (x % j == 0)iansh
//		{
//			return 0;
//		}
//	}
//		return 1;
//
//}
//int main()
//{
//	for (int i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	for (int i = 1; i <= 9; i++)
//	{
//		for (int j = 1; j <= i;j++)
//		{
//			printf("%d * %d=%-2d",i,j,i*j);
//		}
//		printf("\n");
//	}
//	return 0; 
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			printf("%d ", i);
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount=%d", count);
//}
//int  main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("%d%d%d\n", a, b, c);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int a = 0;
//	while (i < 20)
//	{
//		for (;;)
//		{
//			if ((i % 10) == 0)
//				break;
//			else
//				i--;
//		}
//		i += 11;
//		a += i;
//	}
//	printf("%d\n", a);
//	return 0;
//}

//#include<Windows.h>
//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//		Sleep(1000);
//	}
//	return 0;
//}

//int main()
//{
//	char a[1000]; 
//int i;
//for (i = 0; i < 1000; i++)
//{
//	a[i] = -1 - i;
//}
//printf("%d", strlen(a));
//return 0;
//}

//unsigned int i = 0;
//int main()
//{
//	for (i = 0; i <= 255; i++)
//	{
//		printf("Hello\n");
//	}
//	return 0;
//}

//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)            //冒泡排序的趟数
//	{
//		for (j = 0; j < sz - 1 - i; j++)    //冒泡排序的对数
//		{
//			if (arr[j] > arr[j + 1])        
//			{
//				int tmp = 0;
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}

//int main()
//{
//	int i = 0;
//	int arr[] = {100,50,30,60,80,45,12,69,28,11,0,1,2,4};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


int main()
{
	/*char arr[] = "abcdef";
	char* p = arr;
	printf("%s\n", arr);*/
	/*char* p = "abcdef";
	printf("%s\n", p);*/
	char ch = 'w';
	char* pc =&ch;
	printf("%c\n", *pc);
	return 0;
}