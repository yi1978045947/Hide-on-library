#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()
{
	char ch = 'a';  //�ַ�ָ��
	char* pa = &ch;
	char* pb = "abcdef"; //ָ��pb��ŵ����ַ���abcdef�����ַ�a�ĵ�ַ����Ϊ����������������ŵģ����Կ���ͨ�����ַ�a�ĵ�ַ�ҵ������ַ���abcdef
	printf("%c\n", *pb); //"abcdef"��һ�������ַ��������Ըı�
	printf("%s\n", pb);  //%s��ӡ�ַ�����ֻ��Ҫ�ṩ���ַ��ĵ�ַ
	char arr[] = "abcdef";
	printf("%s\n", arr);

	char str1[] = "hello bit.";
    char str2[] = "hello bit.";
    char *str3 = "hello bit.";
    char *str4 = "hello bit.";
	if (str1 == str2)  //str1��str2��������ȫ��ͬ�Ŀռ�
	{
		printf("str1 and str2 are same\n");
	}	
	else
	{
		printf("str1 and str2 are not same\n");
	}
	if (str3 == str4) //str3��str4ָ��ĳ����ַ�������ŵ���hello bit���ַ��ĵ�ַ���ַ������ڴ�����������ŵģ����Կ����ҵ��ַ���hello bit
	{
		printf("str3 and str4 are same\n");
	}		
	else
	{
		printf("str3 and str4 are not same\n");
	}
	return 0;
}