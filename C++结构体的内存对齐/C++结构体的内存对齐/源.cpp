#define _CRT_SECURE_NO_WARNINGS   1

#include <iostream>
using namespace std;

struct X1
{
	char a;
	int b;
	short c;
};

struct X2
{
	char a;
	int b;
	double c;
};

struct X3
{
	char a;
	X2 b;
};

struct X4
{
	char* a;
};

struct X5
{
	double a;
	char b;
	int c;
};

struct X6
{
	double a;
	char b;
	int c;
	char d;
};


int main()
{

	cout << "X1:" << sizeof(X1) << endl;
	cout << "X2:" << sizeof(X2) << endl;
	cout << "X3:" << sizeof(X3) << endl;
	cout << "X4:" << sizeof(X4) << endl;
	cout << "X5:" << sizeof(X5) << endl;
	cout << "X6:" << sizeof(X6) << endl;
	return 0;
}