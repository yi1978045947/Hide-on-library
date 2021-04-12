#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
void reverse_helper(char arr[], char* left, char* right)
{
	if (left >= right)
	{
		return;
	}
	else
	{
		int tmp = 0;
	    tmp = *left;
		*left = *right;
		*right = tmp;
		return reverse_helper(arr, ++left, --right);
	}
}
void reverse(char arr[])
{
	char* left = arr;
	char* right = arr+strlen(arr) - 1;
	reverse_helper(arr, left, right);
}
int main()
{
	char arr[] = "bit education";
	reverse(arr);
	printf("%s\n", arr);
	return 0;
}