#define _CRT_SECURE_NO_WARNINGS   1
#include "game.h"
void game()
{
	char mine[ROWS][COLS] = { 0 }; //不打印在屏幕的数组mine11行11列
	char show[ROWS][COLS] = { 0 };//打印在屏幕上的数组show9行9列
	InitBoard(mine, ROWS,COLS,'0');//初始化数组置为符号0
	InitBoard(show, ROWS, COLS,'*');//初始化数组置为符号*
	//DisplayBoard(mine, ROW,COL);//打印数组显示在屏幕上9行9列
	DisplayBoard(show, ROW,COL);//打印数组显示在屏幕上9行9列
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
		printf("请输入你的选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏!\n");
			break;
		default:
			printf("你输入的有错误，请重新输入!\n");
			break;
		}

	} while (input);
	return 0;
}