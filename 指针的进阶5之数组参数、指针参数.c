#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void print1(int arr2[3][5], int x, int y)  //��ͨ�Ķ�λ�����ӡ�����鴫�Σ��������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
}
void print2(int(*pd)[5], int x, int y) //������ָ��������һά����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", *((*pd + i) + j)); //(*pd+i)���ҵ���i�еĵ�ַ��*((*pd+i)+j)���ҵ���i�е�j�е�Ԫ��
		}
		printf("\n");
	}
}
int main()  //����ָ���ʹ��->ָ�������ָ��
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* pa = &arr;
	int(*pb)[10] = &arr;
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(pa + i));
		printf("%d ",(*pb)[i]);  //*pa<==>arr
		printf("%d ", *(*pb + i));
	}
	printf("\n");

	int arr2[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
	//��ά���鴫�Σ�������Ҳ����Ԫ�ص�ַ����λ�������Ԫ���ǵ�һ��
	//����ȥ���ǵ�һ�еĵ�ַ->һά����ĵ�ַ
	print1(arr2, 3, 5);
	print2(arr2, 3, 5);


	int arr4[5];     //��������
	int* arr5[10];   //ָ�����飬arr5������10��Ԫ�أ�ÿ��Ԫ��������int*
  	int(*pe)[10];    //����ָ�룬peָ��ָ�������������10��Ԫ�أ�ÿ��Ԫ��������int����
	int(*pf[10])[5]; //int(*)[5] ,�������ָ�������,pf��������10��Ԫ�أ�ÿ��Ԫ������������ָ�룬����ָ����5��Ԫ�أ�Ԫ��������int
	return 0;
}