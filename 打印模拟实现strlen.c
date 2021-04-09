#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
int my_strlen3(char arr[])
{
	assert(arr);
	char* start = arr;
	char* end = arr;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;
}
int my_strlen2(char arr[])
{
	assert(arr);
	if (*arr != '\0')
	{
		return 1 + my_strlen2(arr + 1);
	}
	else
	{
		return 0;
	}
}
int my_strlen1(char arr[])
{
	int count = 0;
	assert(arr);
	while (*arr != '\0')
	{
		count++;
		arr++;
	}
	return count;
}
int main()
{
	char arr[] = "bit education";
	int len1 = my_strlen1(arr);
	int len2 = my_strlen2(arr);
	int len3 = my_strlen3(arr);
	printf("%d\n", len1);
	printf("%d\n", len2);
	printf("%d\n", len3);
	return 0;
}