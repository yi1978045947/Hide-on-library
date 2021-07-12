#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<vector>
using namespace std;
void testvector1()
{
	vector<int>v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//v1.push_back(6);
	//v1.push_back(7);
	//v1.push_back(8);
	//while (it != v1.end())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	while (it != v1.end())
	{
		if (*it % 2 == 0)
		{
			v1.erase(it);
		}
		it++;
	}
	while (it != v1.end())
	{
		if (*it % 2 == 0)
		{
			it = v1.erase(it);
		}
		else
		{
			it++;
		}
	}
	vector<int>::iterator vit = v1.begin();
	while (vit != v1.end())
	{
		cout << *vit << " ";
		vit++;
	}
	cout << endl;
}
int main()
{
	testvector1();
	return 0;
}