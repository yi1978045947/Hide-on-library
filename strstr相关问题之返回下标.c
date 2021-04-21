#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<assert.h>
int my_strstr(const char* arr1, const char* arr2)
{
	assert(arr1&&arr2);
	char* p1 = arr1;
	char* p2 = arr2;
	int i = 0;
	int j = 0;
	while (arr1[i] != '\0'&&arr2[j] != '\0')
	{
		if (arr1[i] == arr2[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1; //关键步骤，不相等i回到上一个下标
			j = 0;
		}
	}
	if (arr2[j] == '\0')
	{
		return i - j;
	}
	else
	{
		return -1;
	}
}
int main()
{
	char arr1[] = "bit education";
	char arr2[] = "education";
	int ret=my_strstr(arr1, arr2);
	if (ret == -1)
	{
		printf("查找的字符下标不存在!\n");
	}
	else
	{
		printf("查找的字符串下标是:%d\n", ret);
	}
	return 0;
}