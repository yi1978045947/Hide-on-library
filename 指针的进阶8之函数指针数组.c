#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int main()  //����ָ������
{
	int a = 10;
	int b = 20;
	int* arr[] = { &a, &b };
	//����ָ��->��ź����ĵ�ַ
	int(*pf1)(int, int) = Add;
	int(*pf2)(int, int) = Sub;
	//����ָ������->��ź���ָ�������
	int(*pfarr[2])(int, int) = { Add, Sub };
	return 0;
}