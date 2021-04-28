#define _CRT_SECURE_NO_WARNINGS   1
#include<stdbool.h>
#include<stdio.h>
bool searchMatrix(int** matrix, int matrixSize, int matrixColSize, int target)
{
	if (matrixSize == 0 || matrixSize == 0)
	{
		return false;
	}
	int row = 0;
	int col = matrixColSize - 1;
	while (row<matrixSize&&col >= 0)
	{
		if (matrix[row][col]>target)
		{
			col--;
		}
		else if (matrix[row][col]<target)
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