#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<errno.h>
#include<string.h>

//int main() //fputs�ı������������
//{
//	FILE* pa = fopen("data.txt", "w");
//	if (pa == NULL)
//	{
//		printf("�ļ���ʧ��!\n");
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//дһ������
//		fputs("bit education\n", pa);
//		fputs("bit NB\n", stdout);//�ı��д�ӡ����Ļ��
//		printf("�ļ�д��ɹ�!\n");
//	}
//	fclose(pa);
//	pa = NULL;
//	return 0;
//}

int main() //fgets����������������
{
	char arr[100] = { 0 };
	FILE* pa = fopen("data.txt", "r");
	if (pa == NULL)
	{
		printf("���ļ�ʧ��!\n");
		printf("%s\n", strerror(errno));
		return 1;
	}
	else
	{
		//��һ������
		//fgets(arr, 4, pa); //����bit3���ַ��ٰ���һ��\0����4���ַ���\0���ַ���������־
		//printf("%s\n", arr);
		//printf("�ļ�����ɹ�!\n");

		//����������
	/*	while (fgets(arr, 4, pa) != NULL)
		{
			printf("%s", arr);
		}*/

		//Ҳ���Դ���Ļ������,��׼��������ȡ
		fgets(arr, 4, stdin);
		printf("%s", arr);
		printf("\n");
	}
	return 0;
}