#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	FILE* paIn = fopen("Դ.c", "r");
	if (paIn == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	FILE* paOut = fopen("test.c", "r");
	if (paOut == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	char ch = fgetc(paIn);
	char buff[256] = { 0 };
	//char* res = fets(buff, 256, paIn);
	while (ch != EOF)
	{
		fputs(ch, paOut);
		ch = fgetc(paIn);
		//char* res = fets(buff, 256, paIn); ��ȡһ��������������ַ����ȶ�ȡһ���ַ�����
	}
	fclose(paIn);
	fclose(paOut);
	return 0;
}