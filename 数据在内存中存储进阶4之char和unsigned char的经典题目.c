#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<Windows.h>
int main()
{
	unsigned int i = 0;           //��ʱ��ӡ��9 8 7 6 5 4 3 2 1 0����Ϊ-1���޷������ڴ��в�����ȫ��Ϊ1,i�����0
	for (i = 9; i >= 0; i--)
	{
		printf("%u \n", i);
		Sleep(1000);
	}
	return 0;
}


int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)         //char����Ϊ8λ��ȡֵ��Χ��2^8��-128��127������strlenΪ255
	{
		a[i] = -1 - i;
	}
	printf("%d\n", strlen(a));
	return 0;
}


unsigned char i = 0;
int main()    
{
	for (i = 0; i <= 255; i++)     //��ѭ���Ĵ�ӡbit����Ϊunsigned charȡֵ��Χ��0-255������forѭ����Զ����
	{    
		printf("bit\n");
	}
	return 0;
}