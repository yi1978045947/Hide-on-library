#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
//
//char* my_strcat(char* arr1, const char* arr2)
//{
//	char* ret = arr1;
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	while (*arr1 != '\0')
//	{
//		arr1++;
//	}
//	while (*arr1++ == *arr2++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "education";
//	char arr2[] = "bit";
//	char* ret = my_strcat(arr1, arr2);
//	printf("%s\n", ret);
//	return 0;
//}

int my_strcmp(char* arr1, char* arr2)
{
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	while (*arr1 == *arr2)
	{
		*arr1++;
		*arr2++;
	}
	if (*arr1 > *arr2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	return(*arr1 - *arr2);
}
int main()
{
	char arr1[] = "education";
	char arr2[] = "bit";
	int ret = my_strcmp(arr1, arr2);
	printf("%d\n", ret);
	return 0;
}