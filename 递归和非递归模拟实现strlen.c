#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//int my_strlen(char arr[])
//{
//	int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "bit education";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}
//int my_strlen(char arr[])
//{
//	if (*arr == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(1 + arr);
//	}
//}
//int main()
//{
//	char arr[] = "bit education";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

int my_strlen(char arr[])
{
	char* start = arr;
	char* end = arr;
	while (*end != '\0')
	{
		end++;
	}
	return (end - start);
}
int main()
{
	char arr[] = "bit education";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}