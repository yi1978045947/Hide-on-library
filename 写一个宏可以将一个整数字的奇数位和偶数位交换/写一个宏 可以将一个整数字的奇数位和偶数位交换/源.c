#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//дһ���� ���Խ�һ�������ֵ�����λ��ż��λ����
#define SWAP(i)   ((((i)&0x55555555)<<1)|(((i)&0xaaaaaaaa)>>1))
int main()
{
	int i = 0;	
	scanf("%d", &i);
	printf("ԭ������=%d\n", i);
	printf("����������=%d\n", SWAP(i));
	return 0;
}