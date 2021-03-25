#ifndef _SNAKE_H_
#define _SNAKE_H_
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 500 //�������
#define ROW 20  
#define LINE 20

typedef struct Body
{
	int x;
	int y;
}body;

void MapPrint(char arr[][LINE], int count);//��ͼ��ӡ

void Move(int *row, int *line, char *move);//��ͷ�ƶ�������ͨ����ȡ����ļ��̷�������ı���ͷ����

void GetCoordinate(int *row, int *line, char *move);//��ͷ�Զ��ƶ���ͨ����ȡ�ķ�����Ϣ��������ͷ���ĸ������Զ���

void food(char arr[][LINE], int *x, int *y);//�������һ��ʳ��

void JudgeFood(int food_x, int food_y, int row, int line, int *count);//�ж��Ƿ�Ե�ʳ��

void GetBody(char arr[][LINE], body body[], int count, int temp_x, int temp_y);//�����������

int  Judge(char arr[][LINE], int row, int line);//�ж��Ƿ�ײǽ

void Game();


#endif
