#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	int a = 0; //��λ
	int b = 0; //ʮλ
	int c = 0; //��λ
	for (int i = 100; i <= 999; i++)
	{
		//��ȡ��λ��ÿһλ
		a = (i / 100);
		b = (i / 10) % 10;
		c = i % 10;
		if (a*a*a + b*b*b + c*c*c == i)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}