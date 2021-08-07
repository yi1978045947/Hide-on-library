#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void SelectSort(vector<int>& v)
{
	int left = 0;
	int right = v.size() - 1;
	while (left < right)
	{
		int MinIndex = left;
		int MaxIndex = left;
		for (int i = left; i <=right; i++)
		{
			if (v[i]>v[MaxIndex])
			{
				MaxIndex = i;
			}
			if (v[i] <v[MinIndex])
			{
				MinIndex = i;
			}
		}
		std::swap(v[left], v[MinIndex]);
		if (left == MaxIndex)
		{
			MaxIndex = MinIndex;
		}
		std::swap(v[right], v[MaxIndex]);
		left++;
		right--;
	}
}
int main()
{
	vector<int> v = { 9, 3, 7, 1, 0, 8, 4, 3, 5 };
	SelectSort(v);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}