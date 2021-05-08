#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
{
	int kSize = 0;
	int n = k;
	while (n)
	{
		++kSize;
		n = n / 10;
	}
	int len = kSize>numSize ? kSize + 1 : numSize + 1;  //�������������λ��
	int* retArr = (int*)malloc(sizeof(int)*len);

	int Ai = numSize - 1;
	int Ki = 0;
	int next = 0;

	int reti = 0;

	while (Ai >= 0 || Ki<kSize)
	{
		int aval = 0;
		if (Ai >= 0)  //��num�����Ԫ�طŵ�aval��
		{
			aval = num[Ai];
			Ai--;
		}

		int KVal = k % 10;
		k = k / 10;
		Ki++; //���k��ÿһλ��ֵ

		int ret = aval + KVal + next;  //��ͬ��λ������
		if (ret >= 10)
		{
			next = 1;
			ret = ret - 10;
		}
		else
		{
			next = 0;
		}

		retArr[reti] = ret;  //���Ź���������
		reti++;
	}

	if (next == 1)  //���������λ
	{
		retArr[reti] = 1;
		reti++;
	}

	int begin = 0;
	int end = reti - 1;
	while (begin<end)
	{
		int tmp = retArr[begin];
		retArr[begin] = retArr[end];
		retArr[end] = tmp;
		begin++;
		end--;
	}
	*returnSize = reti;
	return retArr;
}

int main()
{
	return 0;
}