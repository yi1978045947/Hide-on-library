#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
char* my_strcpy(char* arr1, const char* arr2)
{
	assert(arr1&&arr2);
	char* ret = arr1;
	while (*arr1++ = *arr2++)
	{
		;
	}
	return arr1;
}
int main()
{
	char arr1[] = "****************";
	char arr2[] = "bit education";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}