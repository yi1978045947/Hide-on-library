#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//int main()
//{
//	char a = -128;
//	printf("%u\n", a);
//	return 0;
//}
//int main()
//{
//	char a = 128;
//	printf("%u\n", a);
//	return 0;
//}
int main()
{
	char a[1000];
	int i;
	for (i = 0; i<1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));
	return 0;
}