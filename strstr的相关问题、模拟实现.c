#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<assert.h>

//int main() //strstr查找子字符串
//{
//	char arr1[] = "bit education";
//	char arr2[] = "bit";
//	char* ret = strstr(arr1, arr2); //在arr1中查找arr2第一次出现的位置
//	if (ret != NULL)
//	{
//		printf("%s\n", ret);
//	}
//	else
//	{
//		printf("查找的字符串不存在！\n");
//	}
//	return 0;
//}

char* my_strstr(const char* arr1, const char* arr2)
{
	assert(arr1&&arr2);
	const char* cp = arr1;
	while (*cp)
	{
        const char* p1 = cp;
        const char* p2 = arr2;
		while ((*p1 != '\0') && (*p2 != '\0') && (*p1 == *p2))
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			return (char*)cp;
		}
		cp++;
	}
	return NULL;
}
int main()
{
	char arr1[] = "bit education a";
	char arr2[] = "education";
	char* ret = my_strstr(arr1, arr2);
	if (ret != NULL)
	{
		printf("%s\n", ret);
	}
	else
	{
		printf("查找的字符串不存在!\n");
	}
	return 0;
}