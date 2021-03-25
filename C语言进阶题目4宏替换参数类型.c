#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#define N 3+1
#define Y(n)((N+1)*n)

int main()
{
	int z = 0;
	z = 2 * (N + Y(5 + 1));
	printf("z=%d\n", z);
	return 0;
	//2*(3+1+((3+1+1)*5+1)=60
}