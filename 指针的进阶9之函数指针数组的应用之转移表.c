#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
#include<stdlib.h>
void menu()
{
	printf("*****************************\n");
	printf("*****1.ADD    2.Sub      ****\n");
	printf("*****3.Mul    4.Div      ****\n");
	printf("*****         0.Exit     ****\n");
	printf("*****************************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x*y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	int(*pfarr[])(int, int) = { 0, Add, Sub, Mul, Div };  //����ָ�������Ӧ��->ת�Ʊ�
	//do
	//{
	//	menu();
	//	printf("�������ѡ��:>");
	//	scanf("%d", &input);
	//	switch (input)
	//	{
	//	case 1:
	//		printf("����������������:>");
	//		scanf("%d%d", &x, &y);
	//		ret = Add(x, y);
	//		printf("�����:%d\n", ret);
	//		break;
	//	case 2:
	//		printf("����������������:>");
	//		scanf("%d%d", &x, &y);
	//		ret = Sub(x, y);
	//		printf("�����:%d\n", ret);
	//		break;
	//	case 3:
	//		printf("����������������:>");
	//		scanf("%d%d", &x, &y);
	//		ret = Mul(x, y);
	//		printf("�����:%d\n",ret);
	//		break;
	//	case 4:
	//		printf("����������������:>");
	//		scanf("%d%d", &x, &y);
	//		ret = Div(x, y);
	//		printf("�����:%d\n", ret);
	//		break;
	//	case 0:
	//		printf("�˳�����!\n");
	//		exit(1);
	//	default:
	//		printf("�������ѡ���д���,����������!\n");
	//		break;
	//	}
	//} while (input);
	do
	{
		menu();
		printf("���������ѡ��:>");
		scanf("%d", &input);
		if (input == 0)
		{
			printf("�˳�����!\n");
			break;
		}
		else if (input > 0 && input <= 4)
		{
			printf("����������������:");
			scanf("%d%d", &x, &y);
			ret = pfarr[input](x, y);
			printf("�����:%d\n", ret);
		}
	} while (input);
	return 0;
}