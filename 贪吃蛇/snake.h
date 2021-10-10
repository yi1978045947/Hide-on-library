#ifndef _SNAKE_H_
#define _SNAKE_H_
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 500 //蛇身个数
#define ROW 20  
#define LINE 20

typedef struct Body
{
	int x;
	int y;
}body;

void MapPrint(char arr[][LINE], int count);//地图打印

void Move(int *row, int *line, char *move);//蛇头移动函数，通过读取输入的键盘方向键来改变蛇头方向

void GetCoordinate(int *row, int *line, char *move);//蛇头自动移动，通过获取的方向信息，决定蛇头往哪个方向自动移

void food(char arr[][LINE], int *x, int *y);//随机生成一个食物

void JudgeFood(int food_x, int food_y, int row, int line, int *count);//判断是否吃到食物

void GetBody(char arr[][LINE], body body[], int count, int temp_x, int temp_y);//蛇体坐标更新

int  Judge(char arr[][LINE], int row, int line);//判断是否撞墙

void Game();


#endif
