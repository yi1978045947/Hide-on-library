#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<math.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int a1 = 0;
	int a2 = 1;
	int a3 = 0;
	while (1)
	{
		if (n == a2)
		{
			printf("%d\n", 0);
			break;
		}
		else if (n < a2)	
		{
			if (abs(a1 - n)<abs(a2) - n)
			{
				printf("%d\n", abs(a1 - n));
			}
			else
			{
				printf("%d\n", abs(a2 - n));
			}
			break;
		}
		a3 = a1 + a2;
		a1 = a2;
		a2 = a3;
	}
	return 0;
}