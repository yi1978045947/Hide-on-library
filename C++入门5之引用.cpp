#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
void TestConstRef()
{
	//�������Ǵ���һ����ʱ����������������ʱ����������
	const int a = 10;
	//int& ra = a; // ��������ʱ�����aΪ����
	const int& ra = a;
	// int& b = 10; // ��������ʱ�����bΪ����
	const int& b = 10;
	double d = 12.34;
	//int& rd = d; // ��������ʱ��������Ͳ�ͬ
	const int& rd = d;
}
void Swap2(int& a, int& b) //ͨ������������
{
	int tmp = a;
	a = b;
	b = tmp;
}
void Swap1(int* a, int *b) //ͨ��ָ��������
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	int x = 10;
	int &y = x;
	y = 20;
	std::cout << "y=" << y << std::endl;
	int &z = y;
	z = 30;
	std::cout << "z=" << z << std::endl;

	int a = 10;
	int b = 20;
	Swap1(&a, &b);
	std::cout << a << std::endl << b << std::endl;
	Swap2(a, b);
	std::cout << a << std::endl << b << std::endl;
	return 0;
}