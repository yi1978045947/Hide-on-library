#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>
int strStr(char* s1, char* s2)
{
	assert(s1&&s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	char* cp = s1;
	char* start = cp;
	while (*cp)
	{
		char* p1 = cp;
		char* p2 = s2;
		while ((*p1 != '\0') && (*p2 != '\0') && (*p1 == *p2))
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			int ret = cp - start;
			return ret;
		}
		cp++;
	}
	if (len2 == 0)
	{
		return 0;
	}
	else
		return -1;
}
int main()
{
	char arr1[] = "bit edcuation";
	char arr2[] = "bit";
	int ret = strStr(arr1, arr2);
	printf("%d\n", ret);
	return 0;
}