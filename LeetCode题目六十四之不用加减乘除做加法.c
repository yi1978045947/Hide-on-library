#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int add(int a, int b)
{
	while (b)
	{
		int c = (unsigned int)(a&b) << 1;
	    a = a^b; //2^3 10 11  =1 100 1 =101=5
		b = c;
	}
	return a;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	int ret = add(a, b);
	printf("%d\n", ret);
	return 0;

}