#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
void test1()  //test1���ǻص�����
{
	printf("bit education!\n");
}
void test2(void(*p)()) //�ú���ָ��������  -->ͨ��ָ��p�����ú���test1��test1���ǻص�����
{
	p();
}
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
void calc(int(*pfArr)(int,int)) //�Ѻ����ĵ�ַ����ȥ,�ú���ָ�������գ���ô�������߾��ǻص�����
{
	int x = 0;
	int y = 0;
	int ret = 0;
	printf("����������������:>");
	scanf("%d%d", &x, &y);
	ret = pfArr(x, y);
	printf("�����:%d\n", ret);
}
int main()
{
	int input = 0;
	test2(test1); //��test1�����ĵ�ַ����test2<-->���������Ǻ�����ַ
	do
	{
		menu();
		printf("���������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			calc(Add);
			break;
		case 2:
			calc(Sub);
			break;
		case 3:
			calc(Mul);
			break;
		case 4:
			calc(Div);
			break;
		case 0:
			printf("�˳�����!\n");
			break;
		default :
			printf("�������ѡ���д���,����������!\n");
			break;
		}

	} while (input);
	return 0;
}