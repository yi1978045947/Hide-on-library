#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	char ch = 'a';  //字符指针
	char* pa = &ch;
	char* pb = "abcdef"; //指针pb存放的是字符串abcdef中首字符a的地址，因为在数组中是连续存放的，所以可以通过首字符a的地址找到整个字符串abcdef
	printf("%c\n", *pb); //"abcdef"是一个常量字符串不可以改变
	printf("%s\n", pb);  //%s打印字符串，只需要提供首字符的地址
	char arr[] = "abcdef";
	printf("%s\n", arr);

	char str1[] = "hello bit.";
    char str2[] = "hello bit.";
    char *str3 = "hello bit.";
    char *str4 = "hello bit.";
	if (str1 == str2)  //str1与str2是两块完全不同的空间
	{
		printf("str1 and str2 are same\n");
	}	
	else
	{
		printf("str1 and str2 are not same\n");
	}
	if (str3 == str4) //str3与str4指向的常量字符串，存放的是hello bit首字符的地址，字符串在内存中是连续存放的，所以可以找到字符串hello bit
	{
		printf("str3 and str4 are same\n");
	}		
	else
	{
		printf("str3 and str4 are not same\n");
	}
	return 0;
}