#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<Windows.h>
int main()
{
	unsigned int i = 0;           //此时打印完9 8 7 6 5 4 3 2 1 0减减为-1是无符号在内存中补码是全部为1,i恒大于0
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
	for (i = 0; i < 1000; i++)         //char类型为8位，取值范围是2^8是-128到127，所以strlen为255
	{
		a[i] = -1 - i;
	}
	printf("%d\n", strlen(a));
	return 0;
}


unsigned char i = 0;
int main()    
{
	for (i = 0; i <= 255; i++)     //死循环的打印bit，因为unsigned char取值范围是0-255，所以for循环永远成立
	{    
		printf("bit\n");
	}
	return 0;
}