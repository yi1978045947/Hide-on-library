#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<string.h>
#include<errno.h>
//int main() //�ļ��������������
//{
//	//fopen�����������д����ʽ��
//	//����ļ������ڣ��ᴴ������ļ�
//	//����ļ����ڣ�������ļ�������
//	//fopen����������Զ�����ʽ��
//	//�ļ����������ļ���ʧ��
//	FILE* pa = fopen("data.txt", "r"); //Opens for reading. If the file does not exist or cannot be found, the fopen call fails.
//	//FILE* pa = fopen("data.txt", "w"); //Opens an empty file for writing. If the given file exists, its contents are destroyed.
//	if (pa == NULL)
//	{
//		printf("�ļ���ʧ��!\n");
//		printf("%s\n", strerror(errno));
//		return 1; //ʧ�ܷ���
//	}	
//	else
//	{
//		int i = 0;
//		for (i = 'a'; i <= 'z'; i++)
//		{
//			fputc(i , pa);
//		}
//		printf("д���ļ��ɹ�!\n");
//	}
//	             //��д�ļ�
//	fclose(pa); //�ر��ļ�
//	pa = NULL;
//	return 0;
//}
// ���·��
// ../��ʾ��һ��Ŀ¼
// ./��ǰĿ¼
// ./�ļ���//.txt ��һ��·��
// ../../���ϼ�Ŀ¼

// ����·�� �Ӹ�Ŀ¼��ʼд��·�� D:\visua stdio 2013����\�ļ��������������\�ļ��������������

//int main() //fgetc�ʺ�������������
//{
//	//���ļ�
//	FILE* pa =fopen("data.txt", "r");
//	if (pa == NULL)
//	{
//		printf("�ļ���ʧ��!\n");
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//��ȡ�ļ�
//	/*int ch = fgetc(pa);
//	printf("%c\n", ch);*/
//	int ch = 0;
//	while ((ch = fgetc(pa)) != EOF)
//	{
//		printf("%c ", ch);
//	}
//	printf("\n");
//	//�ر��ļ�
//	fclose(pa);
//	pa = NULL;
//	return 0;
//}


int main() //���䣬����������
{
	int ch = 0;
	while ((ch = fgetc(stdin)) != EOF)
	{
		printf("%c\n", ch);
	}
	return 0;
}