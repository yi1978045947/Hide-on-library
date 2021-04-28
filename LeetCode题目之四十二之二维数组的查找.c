#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdbool.h>
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target)
{
	if (matrixSize == 0 || *matrixColSize == 0)
	{
		return false;
	}
	int row = 0;
	int col = *matrixColSize - 1;
	while (row < matrixSize&&col >= 0)
	{
		if (matrix[row][col]>target)
		{
			col--;
		}
		else if (matrix[row][col] < target)
		{
			row++;
		}
		else if (matrix[row][col] == target)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	return 0;
}