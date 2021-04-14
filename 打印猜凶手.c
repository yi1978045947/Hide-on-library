#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	char killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
		{
			printf("killerÊÇ%c\n", killer);
		}
	}

}