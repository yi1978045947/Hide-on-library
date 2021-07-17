#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#if 1
//将结构体首地址设置为0，则结构体成员的地址就是对应的偏移量。
#define offsetof(StructType,MemberName) (size_t)&(((StructType *)0)->MemberName)
typedef struct
{
	char sex;
	int age;
	char name[10];
	char number[10];
}S;

int f(int n)
{
	if (n < 2)
		return n;
	else
		return 2 * f(n - 1) + f(n - 2);
}
int main()
{
	printf("偏移量为%d\n", offsetof(S, sex));
	printf("偏移量为%d\n", offsetof(S, age));
	printf("偏移量为%d\n", offsetof(S, name));
	printf("偏移量为%d\n", offsetof(S, number));

	printf("%d\n", f(5));
	return 0;
}
#endif
