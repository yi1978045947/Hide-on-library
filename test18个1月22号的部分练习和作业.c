#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
//int main()  //链式访问printf返回值是字符(参数)的的个数
//{
//	printf("%d", printf("%d", printf("%d", 43)));
//}

//int main()
//{
//	char arr1[] = "abcd";
//	char arr2[] = { 'a','b','c' };
//	printf("%d\n", sizeof(arr1));
//	printf("%d\n", sizeof(arr2));
//}

void print(int i)
{
	if (i > 9)
	{
		print(i / 10);
	}
	printf("%d", i % 10);
}
int main()
{
	int i = 0;
	scanf("%d", &i);
	print(i);
}