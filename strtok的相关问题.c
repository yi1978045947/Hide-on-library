#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
int main() //strtok根据字符来分割字符串
{
	char arr1[] = "1978045947@qq.com";
	char arr2[40] = { 0 };
	char* pa = "@.";
	strcpy(arr2, arr1);
	//printf("%s\n", strtok(arr2, pa));
	//printf("%s\n", strtok(NULL, pa));
	//printf("%s\n", strtok(NULL, pa));
	char* ret = NULL;
	for (ret = strtok(arr2, pa); ret != NULL; ret =strtok(NULL, pa)) //1.第一次传非空指针，第二次传空指针 2.strtok函数的第一个参数不为 NULL ，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置。3.strtok函数的第一个参数为 NULL ，函数将在同一个字符串中被保存的位置开始，查找下一个标记。
	{
		printf("%s\n", ret);
	}
	return 0;
}