#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
void reverse_string(char* arr, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int tmp = 0;
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
int main()
{
	char arr[] = "bit education";
	int sz = strlen(arr);
	reverse_string(arr, sz);
	printf("%s\n", arr);
	return 0;
}