#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//void swap(int *a, int *b)
//{
//	int tmp = 0;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//int main() //16.�����������������������������������,ע��ֵ���ݣ���ַ����
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	swap(&a, &b);
//	printf("a=%d,b=%d\n", a, b);
//	return 0;
//}

//int main()  //17.����һ���ַ�����ASCII����ʽ���
//{
//	char c = 0;
//	scanf("%c", &c);
//	printf("%d\n", c);
//}

//int main()  //18.����һ�����ʽ��ֵ
//{
//	int a = 40;
//	int c = 212;
//	printf("%d\n",(-8+22) *a - 10 + c / 2);
//	return 0;
//}

//int main() //19.������������a��b,����a����b������������
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	printf("%d %d\n", a / b, a%b);
//	return 0;
//}

int main() //20.һ�У������������ֱ��ʾ����(����),���(����),�м���һ���ո�ָ��� BMIָ��=���ع����������������ƽ���ó�������   ��λ:���������
{
	int weight = 0;
	int height = 0;
	double bmi = 0.0;
	scanf("%d%d", &weight, &height);
	bmi = weight / (height*height / 10000.0);
	printf("%.2f\n", bmi);
}