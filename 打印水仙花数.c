#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<math.h>
//�ж�i�Ƿ�Ϊˮ�ɻ���
//1.���ж�iΪ��λ��
//2.����i��ÿһλ�Ĵη���
//3.�ж�
int main()
{
	int i = 0;
	for (i = 10; i <= 100000; i++)
	{
		int tmp = 1;
		int sum = 0;
		int count = 1; //��¼����Ϊ��λ��
		tmp = i;
		//1.�ж����м�λ
		while (tmp/10)
		{
			count++;
			tmp = tmp / 10;
		}
		//2.��������Ĵη���
		tmp = i; //tmp�жϺ��м�λ������tmp��ֵ���ܸı�,�������°�iֵ��ֵ��tmp;
		while (tmp)
		{
			sum = sum + pow(tmp % 10, count);
			tmp = tmp / 10;
		}
		//3.�жϴ�ʱi�Ƿ����sum���жϸ����Ƿ�Ϊˮ�ɻ���
		if (sum == i)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}