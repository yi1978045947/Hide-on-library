#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
//int main()
//{
//	char arr[20] = { 0 };
//	gets(arr);
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//		}
//		else
//		{
//			arr[i] = toupper(arr[i]);
//		}
//		printf("%c", arr[i]);
//		i++;
//	}
//	printf("\n");
//	return 0;
//}

int main()
{
	int i = 0;
	char arr[30] = { 0 };
	gets(arr);
	if (arr[i] >= 'A'&&arr[i] <= 'Z')
	{
		arr[i] = arr[i] + 32;
		printf("%c", arr[i]);
	}
	if (arr[i] >= 'a'&&arr[i] <= 'z')
	{
		arr[i] = arr[i] - 32;
		printf("%c", arr[i]);
	}
	printf("\n");
	return  0;
}

//int main()
//{
//	int ch = 0;
//	scanf("%c", &ch);
//	if (ch >= 'A'&&ch <= 'Z')
//	{
//		ch = ch + 32;
//	}
//	else
//	{
//		ch = ch - 32;
//	}
//	printf("%c\n", ch);
//	return 0;
//}