#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//写一个宏 可以将一个整数字的奇数位和偶数位交换
#define SWAP(i)   ((((i)&0x55555555)<<1)|(((i)&0xaaaaaaaa)>>1))
int main()
{
	int i = 0;	
	scanf("%d", &i);
	printf("原来数字=%d\n", i);
	printf("交换后数字=%d\n", SWAP(i));
	return 0;
}