#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<errno.h>
int main() //fseek��������⣬�����ļ�ָ���λ�ú�ƫ��������λ�ļ�ָ�롣
{
	FILE* pa = fopen("data.txt", "r");
	if (pa == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int ch = 0;

		/*ch = fgetc(pa);
		printf("%c\n", ch);
		ch = fgetc(pa);
		printf("%c\n", ch); */

		//fseek�����ļ�ָ���λ�ú�ƫ��������λ�ļ�ָ�롣
		//fseek(pa,0, SEEK_CUR);//����SEEK_CUR�ļ���ǰλ�� ����ʼλ��ƫ�������ֽ�
		//fseek(pa,0, SEEK_SET); //����SEEK_SET�ļ���ʼλ�ã���ʼλ�þ���a
		//fseek(pa, -3, SEEK_END); //����SEEK_END�ļ�������־��������־��\0�����Ե�offsetΪ0 ʱ����ȡ������\0
		/*ch = fgetc(pa);
		printf("%c\n", ch);*/

		//rewind(pa); //rewind���ļ�ָ���λ�ûص��ļ�����ʼλ��

		//printf("%d\n", ftell(pa)); //ftell�����ļ�ָ���������ʼλ�õ�ƫ����
		//printf("%c\n", ch);
		while ((ch = fgetc(pa)) != EOF)
		{
			printf("%c ", ch);
		}
		printf("\n");
		if (ferror(pa))
		{
			printf("��ȡʱ��������ʧ�ܶ�����!\n");
		}
		else if (feof(pa))
		{
			printf("�����ļ�ĩβ����!\n");
		}
	}
	fclose(pa);
	pa = NULL;
	
	//������ʹ��fgetc��ȡ��ʱ��,1.������������� 2.��ȡ���ļ�ĩβ������ EOF����
	//������ʹ��fgets��ȡ��ʱ�� 1.������������� 2.��ȡ���ļ�ĩβ������ NULL����
	//������ʹ��fread����ʵ�ʶ�ȡ�ĸ���С��Ҫ���ȡ�������� ����Ҫ���ȡ5����ʵ�ʶ�ȡ4���ͽ�����
	return 0;

	/*  �ļ������ж�
		������ʹ�õ� feof
		�μǣ����ļ���ȡ�����У�������feof�����ķ���ֱֵ�������ж��ļ����Ƿ������
		����Ӧ���ڵ��ļ���ȡ������ʱ���ж��Ƕ�ȡʧ�ܽ��������������ļ�β������
		1. �ı��ļ���ȡ�Ƿ�������жϷ���ֵ�Ƿ�ΪEOF ��fgetc��������NULL��fgets��
		���磺
		fgetc�ж��Ƿ�ΪEOF.
		fgets�жϷ���ֵ�Ƿ�ΪNULL.
		2. �������ļ��Ķ�ȡ�����жϣ��жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�����
		���磺
		fread�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�����*/
}