#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<time.h>
void menu()
{
	printf("*****************************\n");
	printf("*******      1.Play      ****\n");
	printf("*******      0.Exit      ****\n");
	printf("*****************************\n");
}
void game()
{
	int i = 0;
	int ret = rand() % 100 + 1;
	while (1)
	{
		printf("��������Ҫ�²������:>");
		scanf("%d", &i);
		if (i > ret)
		{
			printf("�´���Ŷ!\n");
		}
		else if (i < ret)
		{
			printf("��С��Ŷ!\n");
		}
		else if (i == ret)
		{
			printf("��ϲ��,�¶���!\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));  //���������
	do
	{
		menu();
		printf("���������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�����!\n");
			break;
		default :
			printf("ѡ���������������!\n");
			break;
		}
	} while (input);
	return 0;
}