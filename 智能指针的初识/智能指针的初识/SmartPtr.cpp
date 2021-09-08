#define _CRT_SECURE_NO_WARNINGS   1
#include"RAII.h"
#include<map>

int div()
{
	int a = 0;
	int b = 0;
	cin >> a >> b;
	if (b == 0)
	{
		throw invalid_argument("³ý0´íÎó");
	}
	return a / b;
}
void f1()
{
	SmartPtr<int> sp1(new int);
	*sp1 = 10;
	SmartPtr<pair<int, int>> sp2(new pair < int, int > );
	sp2->first = 20;
	sp2->second = 30;
	cout << div() << endl;
}
int main()
{
	try
	{
		f1();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}