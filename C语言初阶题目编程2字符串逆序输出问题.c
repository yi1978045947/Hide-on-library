#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
void reverse(char* left, char* right)
{
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
//abc def ghi.
//.igh fed cba
int main()
{
	char arr[1000] = { 0 };
	gets(arr);
	int len = strlen(arr);
	reverse(arr, arr + len - 1); //ÄæÐòÕû¸ö×Ö·û´®
	char* start = arr;
	char* end = arr;
	while (*start != '\0')
	{
		end = start;
		while (*end != ' '&&*end != '\0')
		{
			end++;
		}
		reverse(start, end - 1); //ÄæÐòÒ»¸öµ¥´Ê
		if (*end == ' ')
		{
			start = end + 1;
		}
		else
		{
			start = end;
		}
	}
	printf("%s\n", arr);
	return 0;
}