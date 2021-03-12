#define _CRT_SECURE_NO_WARNINGS   1
#include"game.h"
void InitBoard(char Board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			Board[i][j] = ' ';
		}
	}
}
//void DisplayBoard(char Board[ROWS][COLS], int rows, int cols)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < rows; i++)
//	{
//		if (i < rows - 2)
//		{
//			printf(" --- --- ---\n");
//		}
//		printf("| %c | %c | %c |\n", Board[i][0], Board[i][1], Board[i][2]);
//	    printf(" --- --- ---\n");
//	}
//}

void DisplayBoard(char Board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf(" %c ", Board[i][j]);
			if (j < cols - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < rows -1)
		{
			for (j = 0; j < cols; j++)
			{
				printf("---");
				if (j < cols - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void PlayMove(char Board[ROWS][COLS], int rows, int cols)
{
	int x = 0;
	int y = 0;
	printf("玩家走!\n");
	while (1)
	{
		printf("请输入一个坐标:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= rows && y>=1 && y <= cols)
		{
			if (Board[x-1][y-1] != ' ')
			{
				printf("坐标已被输入，请重新输入!\n");
			}
			else
			{
				Board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("输入坐标不合法，请重新输入!\n");
		}
	}
}
void ComputerMove(char Board[ROWS][COLS], int rows, int cols)
{
	printf("电脑走:\n");
	while (1)
	{
		int x = rand() % rows;
		int y = rand() % cols;
		if (Board[x][y] == ' ')
		{
			Board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char Board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j<cols; j++)
		{
			if (Board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char CheckWin(char Board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][0]!=' ')
		{
			return Board[i][0];
		}
	}
	for (i = 0; i < cols; i++)
	{
		if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] &&Board[0][i] != ' ')
		{
			return Board[0][i];
		}
	}
	if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[0][0]!=' ')
	{
		return Board[0][0];
	}
	if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[2][0]!=' ')
	{
		return Board[0][2];
	}
	if (IsFull(Board,rows,cols) == 1)
	{
		return 'Q';
	}
	return 'C';
}