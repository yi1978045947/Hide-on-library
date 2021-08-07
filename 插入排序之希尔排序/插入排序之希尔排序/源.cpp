#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<vector>
using namespace std;

void ShellSort(vector<int>& v)
{
	int gap = v.size();
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (size_t i = 0; i < v.size() - gap; i++)
		{
			int end = i;
			int tmp = v[end + gap]; //先把end后面gap个保存起来，否则往后移会覆盖了
			while (end >= 0)
			{
				if (v[end] >tmp)
				{
					v[end + gap] = v[end];
					end = end - gap;
				}
				else
				{
					break;
				}
			}
			v[end + gap] = tmp;
		}
	}
}
int main()
{
	vector<int> v = { 5, 2, 4, 6, 1, 3 };
	ShellSort(v);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	return 0;
}