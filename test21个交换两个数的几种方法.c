#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>

//void swap(int a, int b)
//{
//	int tmp = 0;
//	tmp = a;
//	a = b;
//	b = tmp;
//	printf("a=%d b=%d\n", a, b);
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	printf("a=%d b=%d\n", a, b);
//	swap(a, b); 
//	return 0;
//}

//void swap(int a, int b)  a,b的值不宜过大，否则会出现越界问题
//{
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("a=%d b=%d\n", a, b);
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	printf("a=%d b=%d\n", a, b);
//	swap(a, b); 
//	return 0;
//}

void swap(int a, int b)
{
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a=%d b=%d\n", a, b);
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	printf("a=%d b=%d\n", a, b);
	swap(a, b);
	return 0;
}