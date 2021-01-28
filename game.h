#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS 3
#define COLS 3

void InitBoard(char Board[ROWS][COLS], int rows, int cols);
void DisplayBoard(char Board[ROWS][COLS], int rows, int cols);
void PlayMove(char Board[ROWS][COLS], int rows, int cols);
void ComputerMove(char Board[ROWS][COLS], int rows, int cols);
char CheckWin(char Board[ROWS][COLS], int rows, int cols);