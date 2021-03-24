#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	unsigned char i = 7;
	int j = 0;
	for (i = 7; i > 0; i -= 3)
	{
		j++;
	}
	printf("%d\n", j);
	return 0;
}

 //解析:4 1(2次) -2(3次)(254) ...(84次) 2-> - 1(255)(85次) ...255/3=85  3+85+85=173