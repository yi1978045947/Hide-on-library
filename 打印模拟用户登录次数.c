#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char arr[100] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("����������:>");
		scanf("%s", arr);
		if (strcmp(arr, "abc") == 0)
		{
			printf("��¼�ɹ�!\n");
			break;
		}
		else
		{
			if (i == 2)
			{
				printf("�������δ����˳�����!\n");
				break;
			}
			printf("�������,����������\n");
		}
	}
	return 0;
}