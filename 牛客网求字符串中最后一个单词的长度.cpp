#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;
int main()
{
	//scanf和cin是以空格，换行结束
	string s;
	while (getline(cin, s))  //换行结束
	{
		size_t pos = s.rfind(' ');
		cout << s.size() - pos - 1 << endl;
	}
	return 0;
}
