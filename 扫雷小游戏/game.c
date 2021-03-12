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
	printf("------------ɨ����Ϸ------------\n");
	for (i = 0; i <=row; i++)
	{
		printf("%d ", i);//��ӡ������0-9
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ������1-9
		for (j = 1; j <= col; j++)
		{
			printf("%c ", Board[i][j]);
		}
		printf("\n");
	}
	printf("------------ɨ����Ϸ------------\n");
}
void SetMine(char mine[ROWS][COLS], int row, int col,int count)//������
{
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] = '0')
		{
			mine[x][y] = '1';
			count--;//���óɹ�������1��cout--
		}
	}
}
int GetMine(char mine[ROWS][COLS], int x, int y)//ͳ��mine����9�������׵ĸ���
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
		printf("������Ҫ���׵�����:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)//�ж�����Ϸ���
		{
			if (mine[x][y] == '1')
			{
				printf("�㱻ը����!\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else//�����ף���ͳ���׵ĸ���
			{
				int count = GetMine(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("���������Ƿ�������������!\n");
		}
	}
	if (win == Easy_Count)
	{
		printf("��ϲ�㣬���׳ɹ�!\n");
	}
}
