#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
	int row = 0;
	int col = 0;
	//ret��һ��ָ��,��ָ�������ָ�빹�ɵ����飬ָ��ָ���Ӧ��������ǵ�һ������retҲ�Ƕ�ά����
	int** ret = (int**)malloc(sizeof(int*)*numRows);
	//ָ��Ҫ���ص�����
	*returnSize = numRows;
	//����ÿһ�еľ���ռ�
	*returnColumnSizes = malloc(sizeof(int)*numRows);
	for (row = 0; row < numRows; row++)
	{
		/* �������������ÿһ�еľ���ռ� */
		ret[row] = malloc(sizeof(int)* (row + 1));
		// �������������ÿһ�е�����
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