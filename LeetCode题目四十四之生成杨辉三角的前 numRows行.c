#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
	int row = 0;
	int col = 0;
	//ret是一个指针,它指向的是由指针构成的数组，指针指向对应的杨辉三角的一行数；ret也是二维数组
	int** ret = (int**)malloc(sizeof(int*)*numRows);
	//指定要返回的行数
	*returnSize = numRows;
	//分配每一列的具体空间
	*returnColumnSizes = malloc(sizeof(int)*numRows);
	for (row = 0; row < numRows; row++)
	{
		/* 分配杨辉三角中每一行的具体空间 */
		ret[row] = malloc(sizeof(int)* (row + 1));
		// 分配杨辉三角中每一行的列数
		(*returnColumnSizes)[row] = row + 1;
		ret[row][row] = ret[row][0] = 1;
		for (col = 1; col < row; col++)
		{
			ret[row][col] = ret[row - 1][col - 1] + ret[row - 1][col];
		}
	}
	return ret;
}
int main()
{
	return 0;
}