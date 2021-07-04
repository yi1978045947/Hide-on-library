#define _CRT_SECURE_NO_WARNINGS   1
#include<stdio.h>
//void swap(int *a, int *b)
//{
//	int tmp = 0;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//int main() //16.输入两个整数，交换两个整数，并输出来,注意值传递，地址传递
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	swap(&a, &b);
//	printf("a=%d,b=%d\n", a, b);
//	return 0;
//}

//int main()  //17.输入一个字符，以ASCII码形式输出
//{
//	char c = 0;
//	scanf("%c", &c);
//	printf("%d\n", c);
//}

//int main()  //18.计算一个表达式的值
//{
//	int a = 40;
//	int c = 212;
//	printf("%d\n",(-8+22) *a - 10 + c / 2);
//	return 0;
//}

//int main() //19.给定两个整数a，b,计算a除以b的整数和余数
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	printf("%d %d\n", a / b, a%b);
//	return 0;
//}

int main() //20.一行，两个整数，分别表示体重(公斤),身高(厘米),中间用一个空格分隔。 BMI指数=体重公斤数除以身高米数平方得出的数字   单位:公斤和厘米
{
	int weight = 0;
	int height = 0;
	double bmi = 0.0;
	scanf("%d%d", &weight, &height);
	bmi = weight / (height*height / 10000.0);
	printf("%.2f\n", bmi);
}