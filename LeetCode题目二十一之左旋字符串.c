#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
char* left_move(char arr1[], int k)
{
	int len = strlen(arr1);
	int i = 0;
	int j = 0;
	for (i = 0; i < k; i++)
	{
		char ret = *arr1;
		for (j = 0; j < len - 1; j++)
		{
			*(arr1 + j) = *(arr1 + j + 1);
		}
		*(arr1 + len - 1) = ret;
	}
	return arr1;
}
int main()
{
	char arr1[] = "bit education";
	int k = 0;
	scanf("%d", &k);
	left_move(arr1, k);
	printf("%s\n", arr1);
	return 0;
}