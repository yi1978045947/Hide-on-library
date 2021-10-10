#define _CRT_SECURE_NO_WARNINGS   1
#include "snake.h"
void gotoxy(int x, int y)//将光标移动到（x,y）位置
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
			//第一行，最后一行，第一列，最后一列都是墙壁
			if (arr[i][j] == 1)
				printf("■");

			else if (arr[i][j] == 2)
				printf("⊙");//蛇头

			else if (arr[i][j] == 3)
				printf("¤");//打印食物¤

			else if (arr[i][j] == 4)
				printf("●");//打印身体●

			else
				printf("  ");//一个墙体占两个空格
		}
		printf("\n");
	}
	printf("				\n");
	printf("             当前得分:%d\n", count);
	printf("				\n");
}
void Move(int *row, int *line, char *move)//蛇头移动函数，通过读取输入的键盘方向键来改变蛇头方向
{
	if (GetAsyncKeyState(VK_UP))//上
	{
		*move = 'w';
	}
	else if (GetAsyncKeyState(VK_DOWN))//下
	{
		*move = 's';
	}
	else if (GetAsyncKeyState(VK_LEFT))//左
	{
		*move = 'a';
	}
	else if (GetAsyncKeyState(VK_RIGHT))//右
	{
		*move = 'd';
	}
	GetCoordinate(row, line, move);//将获得的方向键信息传输过去
}

void GetCoordinate(int *row, int *line, char *move)//蛇头自动移动，通过获取的方向信息，决定蛇头往哪个方向自动移
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

void food(char arr[][LINE], int *x, int *y)//随机生成一个食物
{
	int flag = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (arr[i][j] == 3)//食物为3
				flag = 1;
		}
	}
	if (!flag)//没有食物就生成食物
	{
		//食物不能在边框上
		*x = rand() % (ROW - 2) + 1;
		*y = rand() % (LINE - 2) + 1;
	}
}

void JudgeFood(int food_x, int food_y, int row, int line, int *count)//判断是否吃到食物
{
	if (food_x == row&&food_y == line)//吃到食物
	{
		(*count)++;//吃到食物身体个数+1
	}
}

void GetBody(char arr[][LINE], body body[], int count, int temp_x, int temp_y)//蛇体坐标更新
{
	//保留前一个蛇体的坐标
	int befor_x = 0;
	int befor_y = 0;
	if (count > 0)//最少有一个蛇身
	{
		//记录下最后一个蛇身的位置
		befor_x = body[count - 1].x;
		befor_y = body[count - 1].y;
	}


	int keep = count;//保存一份蛇体个数

	while (count)//蛇体坐标覆盖，后面的覆盖前面的
	{
		if (count == 1)//只有一个蛇体时，为原来蛇头位置
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

	while (keep)//将对应的蛇体坐标赋值
	{
		arr[body[keep - 1].x][body[keep - 1].y] = 4;
		keep--;
	}

	if (befor_x != 0)//最后一个蛇身的上一次所在位置清空
	{
		arr[befor_x][befor_y] = 0;
	}

}

int  Judge(char arr[][LINE], int row, int line)//判断是否撞墙
{
	if (arr[row][line] == 1)
	{
		printf("	 --------------\n");
		printf("	|   撞到墙壁   |\n");
		printf("	|   游戏结束   |\n");
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

	};//地图
	int row = 10, line = 10;//蛇头起始位置
	arr[row][10] = 2;
	char move = 'w';//蛇头开始往上移动
	int food_x = 0, food_y = 0;//食物的x,y坐标
	srand((unsigned)time(NULL));//随机数种子
	//保留一份蛇头移动前坐标
	int temp_x = row;
	int temp_y = line;
	int count = 0;//蛇身体个数
	body body[MAX] = { 0 };//蛇身坐标记录结构体数组

	while (1)
	{
		//生成食物
		food(arr, &food_x, &food_y);
		arr[food_x][food_y] = 3;

		MapPrint(arr, count);//打印图形

		if (count == 0)
			arr[row][line] = 0;//没有身体的时候,蛇头原来位置变为空白

		//保留蛇头移动前的位置
		temp_x = row;
		temp_y = line;

		Move(&row, &line, &move);//蛇头移动

		if (Judge(arr, line, row) == 0)//判断是否撞墙
		{
			break;
		}

		JudgeFood(food_x, food_y, row, line, &count);//判断是否吃到食物
		GetBody(arr, body, count, temp_x, temp_y);//蛇身构造
		arr[row][line] = 2;//新位置变成蛇头

		Sleep(500);//通过控制休眠时间来控制蛇头移动速度
	}
}



