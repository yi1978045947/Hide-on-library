#define _CRT_SECURE_NO_WARNINGS   1
#include "snake.h"
void gotoxy(int x, int y)//������ƶ�����x,y��λ��
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);


}
void MapPrint(char arr[][LINE], int count)
{
	gotoxy(0, 0);
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < LINE; j++)
		{
			//��һ�У����һ�У���һ�У����һ�ж���ǽ��
			if (arr[i][j] == 1)
				printf("��");

			else if (arr[i][j] == 2)
				printf("��");//��ͷ

			else if (arr[i][j] == 3)
				printf("��");//��ӡʳ���

			else if (arr[i][j] == 4)
				printf("��");//��ӡ�����

			else
				printf("  ");//һ��ǽ��ռ�����ո�
		}
		printf("\n");
	}
	printf("				\n");
	printf("             ��ǰ�÷�:%d\n", count);
	printf("				\n");
}
void Move(int *row, int *line, char *move)//��ͷ�ƶ�������ͨ����ȡ����ļ��̷�������ı���ͷ����
{
	if (GetAsyncKeyState(VK_UP))//��
	{
		*move = 'w';
	}
	else if (GetAsyncKeyState(VK_DOWN))//��
	{
		*move = 's';
	}
	else if (GetAsyncKeyState(VK_LEFT))//��
	{
		*move = 'a';
	}
	else if (GetAsyncKeyState(VK_RIGHT))//��
	{
		*move = 'd';
	}
	GetCoordinate(row, line, move);//����õķ������Ϣ�����ȥ
}

void GetCoordinate(int *row, int *line, char *move)//��ͷ�Զ��ƶ���ͨ����ȡ�ķ�����Ϣ��������ͷ���ĸ������Զ���
{
	if (*move == 'w')
		(*row)--;
	else if (*move == 's')
		(*row)++;
	else if (*move == 'a')
		(*line)--;
	else if (*move == 'd')
		(*line)++;
}

void food(char arr[][LINE], int *x, int *y)//�������һ��ʳ��
{
	int flag = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (arr[i][j] == 3)//ʳ��Ϊ3
				flag = 1;
		}
	}
	if (!flag)//û��ʳ�������ʳ��
	{
		//ʳ�ﲻ���ڱ߿���
		*x = rand() % (ROW - 2) + 1;
		*y = rand() % (LINE - 2) + 1;
	}
}

void JudgeFood(int food_x, int food_y, int row, int line, int *count)//�ж��Ƿ�Ե�ʳ��
{
	if (food_x == row&&food_y == line)//�Ե�ʳ��
	{
		(*count)++;//�Ե�ʳ���������+1
	}
}

void GetBody(char arr[][LINE], body body[], int count, int temp_x, int temp_y)//�����������
{
	//����ǰһ�����������
	int befor_x = 0;
	int befor_y = 0;
	if (count > 0)//������һ������
	{
		//��¼�����һ�������λ��
		befor_x = body[count - 1].x;
		befor_y = body[count - 1].y;
	}


	int keep = count;//����һ���������

	while (count)//�������긲�ǣ�����ĸ���ǰ���
	{
		if (count == 1)//ֻ��һ������ʱ��Ϊԭ����ͷλ��
		{
			body[count - 1].x = temp_x;
			body[count - 1].y = temp_y;
		}
		else
		{
			body[count - 1].x = body[count - 2].x;
			body[count - 1].y = body[count - 2].y;
		}
		count--;
	}

	while (keep)//����Ӧ���������긳ֵ
	{
		arr[body[keep - 1].x][body[keep - 1].y] = 4;
		keep--;
	}

	if (befor_x != 0)//���һ���������һ������λ�����
	{
		arr[befor_x][befor_y] = 0;
	}

}

int  Judge(char arr[][LINE], int row, int line)//�ж��Ƿ�ײǽ
{
	if (arr[row][line] == 1)
	{
		printf("	 --------------\n");
		printf("	|   ײ��ǽ��   |\n");
		printf("	|   ��Ϸ����   |\n");
		printf("	 --------------\n");
		system("pause");
		return 0;
	}
	return 1;
}

void Game()
{
	char arr[ROW][LINE] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },

	};//��ͼ
	int row = 10, line = 10;//��ͷ��ʼλ��
	arr[row][10] = 2;
	char move = 'w';//��ͷ��ʼ�����ƶ�
	int food_x = 0, food_y = 0;//ʳ���x,y����
	srand((unsigned)time(NULL));//���������
	//����һ����ͷ�ƶ�ǰ����
	int temp_x = row;
	int temp_y = line;
	int count = 0;//���������
	body body[MAX] = { 0 };//���������¼�ṹ������

	while (1)
	{
		//����ʳ��
		food(arr, &food_x, &food_y);
		arr[food_x][food_y] = 3;

		MapPrint(arr, count);//��ӡͼ��

		if (count == 0)
			arr[row][line] = 0;//û�������ʱ��,��ͷԭ��λ�ñ�Ϊ�հ�

		//������ͷ�ƶ�ǰ��λ��
		temp_x = row;
		temp_y = line;

		Move(&row, &line, &move);//��ͷ�ƶ�

		if (Judge(arr, line, row) == 0)//�ж��Ƿ�ײǽ
		{
			break;
		}

		JudgeFood(food_x, food_y, row, line, &count);//�ж��Ƿ�Ե�ʳ��
		GetBody(arr, body, count, temp_x, temp_y);//������
		arr[row][line] = 2;//��λ�ñ����ͷ

		Sleep(500);//ͨ����������ʱ����������ͷ�ƶ��ٶ�
	}
}



