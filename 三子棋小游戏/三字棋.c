#define _CRT_SECURE_NO_WARNINGS   1
#include "game.h"
void menu()
{
	printf("**************************\n");
	printf("********  1.play      ****\n");
	printf("********  0.exit      ****\n");
	printf("**************************\n");
}
void game()
{
	char ret = 0;
	char Board[ROWS][COLS] = { 0 };
	InitBoard(Board, ROWS, COLS);
	DisplayBoard(Board, ROWS, COLS);
	while (1)
	{
		PlayMove(Board, ROWS, COLS);
	    ret = CheckWin(Board, ROWS, COLS);
	/*	if (ret != 'C')
		{
			break;
		}*/
		DisplayBoard(Board, ROWS, COLS);
		ComputerMove(Board, ROWS, COLS);
		ret = CheckWin(Board, ROWS, COLS);
	/*	if (ret != "C")
		{
			break;
		}*/
		DisplayBoard(Board, ROWS, COLS);
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢!\n");
	}
	else if (ret == 'Q')
	{
		printf("平局!\n");
	}
	DisplayBoard(Board, ROWS, COLS);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入你的选择:>");
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
			printf("你选择的有错误，请重新输入!\n");
			break;
		}
	} while (input);
	return 0;
}
