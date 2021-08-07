#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<vector>
using namespace std;

void InsertSort(vector<int>& v)
{
	for (size_t i = 0; i < v.size()-1; i++)
	{
		int end = i;
		int tmp = v[end + 1];

		while (end >= 0)
		{
			if (v[end]>tmp)
			{
				v[end + 1] = v[end];
				end = end - 1;
			}
			else
			{
				break;
			}
		}
		v[end + 1] = tmp;
	}
}
int main()
{
	vector<int> v;
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(6);
	v.push_back(1);
	v.push_back(3);
	InsertSort(v);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	return 0;
}