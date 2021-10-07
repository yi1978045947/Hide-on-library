#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

class UnionFindSet
{
public:
	UnionFindSet(size_t n)
	{
		_ufs.resize(n, -1);
	}

	int FindRoot(int x)
	{
		assert(x < _ufs.size());
		while (_ufs[x] >= 0)
		{
			x = _ufs[x];
		}
		return x;
	}

	void Union(int x1, int x2)
	{
		assert(x1 < _ufs.size());
		assert(x2 < _ufs.size());

		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		if (root1 == root2)
		{
			return;
		}
		if (root1 != root2)
		{
			_ufs[root1] += _ufs[root2];
			_ufs[root2] = root1;
		}
	}

	//负数的个数就是集合的个数
	size_t SetSize()
	{
		size_t count = 0;
		for (size_t i = 0; i < _ufs.size(); i++)
		{
			if (_ufs[i] < 0)
			{
				count++;
			}
		}
		return count;
	}
private:
	vector<int> _ufs;
};
class Solution {
public:
	int findCircleNum(vector<vector<int>>& isConnected)
	{
		UnionFindSet ufs(isConnected.size());
		for (size_t i = 0; i<isConnected.size(); i++)
		{
			for (size_t j = 0; j<isConnected.size(); j++)
			{
				if (isConnected[i][j] == 1)
				{
					ufs.Union(i, j);
				}
			}
		}
		return ufs.SetSize();
	}
};