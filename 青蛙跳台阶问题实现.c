#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int jump(int n)
{
	if (n == 1 || n == 2)
	{
		return n;  //n==1ʱ����һ��������n==2ʱ������������
	}
	else          //nΪ3��ʼ�ݹ�
	{
		return jump(n - 1) + jump(n - 2);
	}
}
int main()
{
	int n = 0;
	printf("����������̨����:>");
	scanf("%d", &n);
	int sum = jump(n);
	printf("һ����%d�ַ���!\n",sum);
	return 0;
}