#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<math.h>
//void print(int i) //��ӡһ������ÿһλ��123��ӡ�� 1 2 3
//{
//	int sum = 0;
//	if (i > 9)
//	{
//		print(i / 10);
//	}
//	printf("%d ", i % 10);
//}
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	print(i);
//}

//int jiecheng(int n)   //��׳ˣ��ǵݹ�
//{
//	int a = 1;
//	int b = 0;
//	for (b = 1; b <= n; b++)
//	{
//		a =  a*b;
//	}
//	return a;
//}
//int main()
//{
//	int n = 0;
//	int sum = 0;
//	scanf("%d", &n);
//	sum = jiecheng(n);
//	printf("%d\n", sum);
//}

//int jiecheng(int n)  ��׳ˣ��ݹ鷽ʽ
//{
//	if (n >= 2)
//	{
//		return n*(jiecheng(n - 1));
//	}
//	return 1;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret=jiecheng(n);
//	printf("%d\n", ret);
//}

//int my_strlen(char* arr)  �ǵݹ���strlen
//{
//	int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		*arr++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcde";
//	int length = my_strlen(arr);
//	printf("%d\n", length);
//}

//int my_strlen(char* arr) �ݹ�ʵ��strlen
//{
//	if (*arr != '\0')
//	{
//		return 1 + my_strlen(arr+1);
//	}
//	return 0;
//}
//int main()
//{
//	char arr[] = "abcde";
//	int length = my_strlen(arr);
//	printf("%d\n", length);
//	return 0;
//}


//int fun(int n)�ݹ���쳲�����
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return fun(n - 1) + fun(n - 2);
//	}
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = fun(n);
//	printf("%d\n", ret);
//	return 0;
//}

//int fun(int n) �ǵݹ���쳲�������
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n >2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = fun(n);
//	printf("%d\n", ret);
//}

//int fun(int n, int k) ��n��k�η�
//{
//	if ( k <=0 )
//	{
//		return 1; 
//	}
//	else if (k>=1)
//	{
//		return n*fun(n, k-1);
//	}
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	int ret = 0;
//	scanf("%d%d", &n,&k);
//	ret = fun(n, k);
//	printf("%d\n", ret);
//}


//int DigitSum(int n) ��һ�����ĸ���λ֮��
//{
//	if (n < 10)
//	{
//		return n;
//	}
//	else if (n >= 10)
//	{
//		return n % 10 + DigitSum(n/10);
//	}
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = DigitSum(n);
//	printf("%d\n", ret);
//	return 0;
//}

void reverse_string(char arr[],int sz) 
{
	int left = 0;
	int right = sz - 1;
	char tmp = 0;
	while (left < right)
	{
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
	printf("%s\n", arr);
}
int main()
{
	char arr[] = "abcdef";
	int sz = sizeof(arr) / sizeof(arr[0]);
	reverse_string(arr,sz);
	return 0;
}


