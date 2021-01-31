#define _CRT_SECURE_NO_WARNINGS   1
#include <stdio.h>
//int main()
//{
//	int i = 1;
//	int ret = (++i) + (++i) + (++i);
//	printf("ret = %d\n", ret);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int i = 0;
//	int count = 0;
//	scanf("%d%d", &a, &b);
//	c = a ^ b;//c的二进制有几个1就是有几个不同
//	for (i = 0; i < 32; i++)
//	{
//		if (((c >> i) & 1) == 1)//每次右移都拿c的最后一个二进制位按位与1，如果得出的结果是1，则计数器自增一次
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}
//
//int get_differ(int i, int j)
//{
//	int count = 0;
//	int tmp = 0;
//	tmp = i^j;//tmp中二进制1的个数就是i，j不同位的个数
//	while (tmp)
//	{
//		tmp = tmp&(tmp - 1);//用tmp按位与tmp-1得出count
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int count = 0;
//	scanf("%d%d", &i, &j);
//	count = get_differ(i, j);
//	printf("%d\n", count);
//}

//void print(int i)
//{
//	int a = 0;
//	for (a = 31; a >= 1; a -= 2)//奇数二进制位
//	{
//		printf("%d ", (i >> a) & 1);
//	}
//	printf("\n");
//	for (a = 32; a >= 0; a -= 2)//偶数二进制位
//	{
//		printf("%d ", (i >> a) & 1);
//	}
//	printf("\n");
//}
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	print(i);
//	return 0;
//}

//int statistics(int i)统计二进制位中一个个数
//{
//	int a = 0;
//	int count = 0;
//	for (a = 0; a < 32; a++)
//	{
//		if (((i >> a) & 1) == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	int count = statistics(i);
//	printf("%d \n", count);
//	return 0;
//}

//int stat(int i)  统计二进制位中1的个数，这种方法不能求负数
//{
//	int count = 0;
//	while (i)
//	{
//		if (i % 2==1)
//		{
//			count++;
//		}
//		i= i / 2;
//	}
//	return count;
//}
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	int count = stat(i);
//	printf("%d\n", count);
//	return 0;
//}