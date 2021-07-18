#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> st1;
	st1.push(1);
	st1.push(2);
	st1.push(3);
	st1.push(4);
	cout << st1.empty() << endl;
	cout << st1.size() << endl;
	//Ã»ÓÐµü´úÆ÷
	while (!st1.empty())
	{
		cout << st1.top() << " ";
		st1.pop();
	}
	cout << endl;
	return 0;
}