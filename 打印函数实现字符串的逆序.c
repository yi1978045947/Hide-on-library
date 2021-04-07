#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
void reverse(char arr[],int len)
{
	int left = 0;
	int right = len - 1;
	while (left <= right)
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
	int len = strlen(arr);
	reverse(arr,len);
	printf("%s\n", arr);
	return 0;
}