#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int a = 1;
void test()
{
	int a = 2;
	a += 1;  //�ֲ���������ȫ�ֱ���������ͬʱ���ֲ��������� a=a+1=3
}
int main()
{
	test();
	printf("%d\n", a);
	return 0;
}