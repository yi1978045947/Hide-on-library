#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int Fib(int n,int first,int second)  //β�ݹ鷽��ͨ�����������������ֵ�����ݸ���һ�ν��м��㣬\
                                     �ݹ�Ĺ�����Ҳ�Ǹ���nֵ�仯���ظ����㣬��ѭ����࣬\
                                      ʱ�临�ӶȺͿռ临�Ӷ�Ҳ��һ�������Ǳ�ѭ������࣬������
{
	if (n <= 1)
	{
		return first;
	}
	else
	{
		return Fib(n - 1, second, first + second);
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int first = 1;
	int second = 1;
	int ret = Fib(n, first, second);
	printf("%d\n", ret);
	return 0;
}