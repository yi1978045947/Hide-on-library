#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
//���ʵ��һ��ͨ�õĽ��������أ�
void swap(int& left, int &right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
void swap(double& left, double& right)
{
	double tmp = left;
	left = right;
	right = tmp;
}
void swap(char& left, char& right)
{
	char tmp = left;
	left = right;
	right = tmp;
}
int main()
{
	int a = 10;
	int b = 20;
	swap(a, b);
	std::cout << a << " "<< b << std::endl;
	int c = 1.0;
	int d = 2.0;
	swap(c, d);
	std::cout << c << " "<< d << std::endl;
	char e = 'a';
	char f = 'b';
	swap(e, f);
	std::cout << e << " " << f << std::endl;
	return 0;
}
//ʹ�ú���������Ȼ����ʵ�֣�������һ�¼������õĵط���
//1. ���صĺ�������ֻ�����Ͳ�ͬ������ĸ����ʱȽϵͣ�ֻҪ�������ͳ���ʱ������Ҫ���Ӷ�Ӧ�ĺ���
//2. ����Ŀ�ά���ԱȽϵͣ�һ������������е����ؾ�����