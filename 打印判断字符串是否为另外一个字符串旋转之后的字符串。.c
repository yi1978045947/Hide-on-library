#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>
void reverse(char* left, char* right)
{
	assert(left&&right);
	while (left < right)
	{
		char tmp = 0;
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
char* left_move(char* arr2,int k)
{
	assert(arr2);
	int len = strlen(arr2);
	reverse(arr2, arr2 + k - 1);
	reverse(arr2 + k, arr2 + len - 1);
	reverse(arr2, arr2 + len - 1);
	return arr2;
}
int is_left_move1(char* arr1, char* arr2) //方法1
{
	int len = strlen(arr2);
	while (len--)
	{
		left_move(arr2,1);
		if (strcmp(arr1, arr2) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int is_left_move2(char* arr1, char* arr2)  //方法2
{
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
	{
		return 0;
	}
	strncat(arr1, arr1, len1);
	if (strstr(arr1, arr2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	char arr1[] = "bit education";
	char arr2[] = "bit education";
	if (is_left_move1(arr1, arr2))
	{
		printf("OK!\n");
	}
	else
	{
		printf("NO!\n");
	}
	return 0;
}