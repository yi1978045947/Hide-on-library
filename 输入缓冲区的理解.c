#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int main()  //���뻺�����ĸ���,Ҫ�Ȱ�\n�ַ���ȡ��
{
	char password[20];
	printf("�������������:>");
	scanf("%s", password);
	printf("��ȷ��(Y/N):>");
	getchar();
	int ch = getchar();
	if (ch == 'Y')
	{
		printf("ȷ�ϳɹ�!\n");
	}
	else
	{
		printf("ȷ��ʧ��!\n");
	}
	return 0;
}