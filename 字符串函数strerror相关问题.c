#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<errno.h>
int main() //strerror���󱨸溯��,�⺯����������
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		perror(""); //���strerror������perror��װ����Щ��Ϣ
	}
	return 0;
}