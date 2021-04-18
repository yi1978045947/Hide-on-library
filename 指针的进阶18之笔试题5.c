#define _CRT_SECURE_NO_WARNINGS   1
#include <stdio.h>
int main()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	int *p;
	p = a[0];
	printf("%d\n", p[0]);
	return 0;
}
