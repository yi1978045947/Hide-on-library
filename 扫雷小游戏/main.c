#define _CRT_SECURE_NO_WARNINGS   1
#include "game.h"
void game()
{
	char mine[ROWS][COLS] = { 0 }; //����ӡ����Ļ������mine11��11��
	char show[ROWS][COLS] = { 0 };//��ӡ����Ļ�ϵ�����show9��9��
	InitBoard(mine, ROWS,COLS,'0');//��ʼ��������Ϊ����0
	InitBoard(show, ROWS, COLS,'*');//��ʼ��������Ϊ����*
	//DisplayBoard(mine, ROW,COL);//��ӡ������ʾ����Ļ��9��9��
	DisplayBoard(show, ROW,COL);//��ӡ������ʾ����Ļ��9��9��
	SetMine(mine, ROW, COL,Easy_Count);
	//DisplayBoard(mine, ROW, COL);//
	FindMine(mine,show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do{
		menu();
		printf("���������ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ!\n");
			break;
		default:
			printf("��������д�������������!\n");
			break;
		}

	} while (input);
	return 0;
}