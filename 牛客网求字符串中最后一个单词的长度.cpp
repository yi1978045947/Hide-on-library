#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;
int main()
{
	//scanf��cin���Կո񣬻��н���
	string s;
	while (getline(cin, s))  //���н���
	{
		size_t pos = s.rfind(' ');
		cout << s.size() - pos - 1 << endl;
	}
	return 0;
}
