#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;

//int sum(int a, int b = 5, int z = 10);
//void main()
//{
//	int x(10), y(3), z(4);
//	int s;
//	s = sum(x, y, z);
//	cout << "s=" << s << endl;
//	s = sum(x, y);
//	cout << "s=" << s << endl;
//	s = sum(x);
//	cout << "s=" << s << endl;
//}
//
//int sum(int a, int b, int c)
//{
//	cout << "a=" << a << "\tb=" << b << "\tc=" << c << endl;
//	return (a + b + c);
//}

int maxtwo(int x, int y);
int maxthree(int x, int y, int z);
void main()
{
	int a, b, c;
	cout << "��������������ֵ:";
	cin >> a >> b >> c;
	cout << "������" << a << "," << b << "," << c << "�е�������ǣ�" << maxthree(a, b, c) << endl;
}
int maxtwo(int x, int y)
{
	cout << "��������������е����ֵ��������" << endl;
	if (x > y)
		return x;
	return y;
}

int  maxthree(int x, int y, int z)
{
	cout << "��������������е����ֵ��������" << endl;
	int max;
	max = maxtwo(x, y);
	max = maxtwo(max, z);
	return max;
}