#define _CRT_SECURE_NO_WARNINGS   1
#include"game.h"
void menu()
{
	printf("***************************\n");
	printf("**********1.play***********\n");
	printf("**********0.exit***********\n");
	printf("***************************\n");
}
void InitBoard(char Board[ROWS][COLS], int rows, int cols,char ret)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			Board[i][j] = ret;
		}
	}
}
void DisplayBoard(char Board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------------扫雷游戏------------\n");
	for (i = 0; i <=row; i++)
	{
		printf("%d ", i);//打印行坐标0-9
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印列坐标1-9
		for (j = 1; j <= col; j++)
		{
			printf("%c ", Board[i][j]);
		}
		printf("\n");
	}
	printf("------------扫雷游戏------------\n");
}
void SetMine(char mine[ROWS][COLS], int row, int col,int count)//布置雷
{
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] = '0')
		{
			mine[x][y] = '1';
			count--;//布置成功则雷少1，cout--
		}
	}
}
int GetMine(char mine[ROWS][COLS], int x, int y)//统计mine数组9宫格中雷的个数
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-Easy_Count)
	{
		printf("请输入要排雷的坐标:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)//判断坐标合法性
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了!\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else//不是雷，则统计雷的个数
			{
				int count = GetMine(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入的坐标非法，请重新输入!\n");
		}
	}
	if (win == Easy_Count)
	{
		printf("恭喜你，排雷成功!\n");
	}
}
