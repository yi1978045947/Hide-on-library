#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#if 1
//���ṹ���׵�ַ����Ϊ0����ṹ���Ա�ĵ�ַ���Ƕ�Ӧ��ƫ������
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
	printf("ƫ����Ϊ%d\n", offsetof(S, sex));
	printf("ƫ����Ϊ%d\n", offsetof(S, age));
	printf("ƫ����Ϊ%d\n", offsetof(S, name));
	printf("ƫ����Ϊ%d\n", offsetof(S, number));

	printf("%d\n", f(5));
	return 0;
}
#endif
