#define _CRT_SECURE_NO_WARNINGS   1
#include <stdio.h>
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5 };
//	short *p = (short*)arr;
//	int i = 0;
//	for (i = 0; i<4; i++)
//	{
//		*(p + i) = 0;
//	}
//
//	for (i = 0; i<5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int arr[] = { 5, 4, 2, 3, 1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p = &arr;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	printf("\n");
//	return 0;
//}
#include<string.h>
//void print(char* str) �����ӡ
//{
//	char* left = str;
//	char* right = str + strlen(str) - 1;
//	while (left<right)
//	{
//		char  tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[] = "I am a student";
//	print(arr);
//	printf("%s ", arr);
//	printf("\n");
//	return 0;
//}

//int main() ��22222��ÿ��λ�����
//{
//	int a = 0;
//	int n = 0;
//	int i = 0;
//	scanf("%d %d", &a, &n);
//	int ret=0 ;
//	int sum=0 ;
//	for (i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sum = sum + ret;
//	}
//	printf("%d\n", sum);
//}
#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100000; i++ )
//	{
//		int sum = 0;
//		int n = 1;
//		int tmp = 1;
//		while ( tmp / 10)//�ж�i��λ��
//		{
//			n++;
//			tmp = tmp / 10;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum = sum + pow(tmp % 10, n);
//			tmp = tmp / 10;
//		}
//		if( sum==i )
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 999999; i++)
//	{
//		int count = 1;
//		int tmp = i;
//		int sum = 0;
//		//�ж�i�Ƿ�Ϊˮ�ɻ���
//		//1. ���ж����ֵ�λ��
//		while (tmp / 10)
//		{
//			count++;
//			tmp = tmp / 10;
//		}
//
//		//2. ����ÿһλ�Ĵη���
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, count);
//			tmp = tmp / 10;
//		}
//
//		//3. �ж�
//		if (sum == i)
//			printf("%d ", i);
//	}
//	printf("\n");
//	return 0;
//}

//
//int main()��ˮ����10Ԫ��19ƿ
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	scanf("%d", &money);
//	total = money;
//	empty = money;
//	while (empty >= 2)
//	{
//		total = total + empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n",total);
//}

int main()
{
	int line = 0;
	int i = 0;
	scanf("%d", &line);//7
	//��ӡ�ϰ벿��
	for (i = 0; i<line; i++)
	{
		//��ӡһ��
		//��ӡ�ո�
		int j = 0;
		for (j = 0; j<line - 1 - i; j++)
		{
			printf(" ");
		}
		//��ӡ*
		for (j = 0; j<2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//��ӡ�°벿��
	for (i = 0; i<line - 1; i++)
	{
		//��ӡһ��
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (j = 0; j<2 * (line - 1 - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}