#define _CRT_SECURE_NO_WARNINGS   

#include<iostream>
using namespace std;
namespace yyw
{
	int div(int n, int m)
	{
		if (m == 0)
		{
			//throw - 1;
			throw "������0����!";
			//throw string("������0����!");
		}
		return n / m;
	}
}
int main()
{
	try
	{
		int n = 0;
		int m = 0;
		cin >> n >> m;
		cout << yyw::div(n, m) << endl;
	}
	catch (int err)
	{
		cout << err << endl;
	}
	catch (const char* err)
	{
		cout << err << endl;
	}
	catch (...)
	{
		cout << "unkown exception!" << endl;
	}
}