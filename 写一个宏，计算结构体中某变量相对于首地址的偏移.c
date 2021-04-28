#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#if 1
#define offset_of_first(StructType,MemberName) (size_t)&(((StructType *)0)->MemberName)
typedef struct
{
	char sex;
	int age;
	char name[10];
	char number[10];
}S;

int main()
{
	printf("偏移量为%d\n", offset_of_first(S, sex));
	printf("偏移量为%d\n", offset_of_first(S, age));
	printf("偏移量为%d\n", offset_of_first(S, name));
	printf("偏移量为%d\n", offset_of_first(S, number));
	return 0;
}
#endif
