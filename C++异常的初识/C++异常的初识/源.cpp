#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	try
	{
		vector<int> v = { 1, 2, 3, 4, 5, 6 };
		for (int i = 0; i <= v.size(); i++)
		{
			//cout << v[i] << " ";
			cout << v.at(i) << " ";
		}
		cout << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

