#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<Windows.h>
int main()  //���뻺���������
{
	FILE* pa = fopen("data.txt", "w");  //���ļ�
	if (pa == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else                                //д���ļ�
	{
		fputs("abcde", pa);
		printf("˯��10s,д��������������!\n");
		Sleep(10000);
		fflush(pa);  //ע��fflush��vs�ߵİ汾����ʹ��
		printf("��˯��10s,��ʱ��data.txt�ĵ�����������!\n");
		Sleep(10000);
	}
		fclose(pa);
		pa = NULL;                 //�ر��ļ�
	return 0;
}