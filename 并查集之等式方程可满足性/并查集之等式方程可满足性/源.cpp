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

	//�����ĸ������Ǽ��ϵĸ���
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
	bool equationsPossible(vector<string>& equations)
	{
		UnionFindSet ufs(26);
		//��һ�飬�Ȱ���ȵ�ֵ�ϲ���һ������
		for (const auto& str : equations)
		{
			if (str[1] == '=')
			{
				ufs.Union(str[0] - 'a', str[3] - 'a');
			}
		}
		//�ڶ���,�Ѳ���ȵ�ֵ�ж��ڲ���ͬһ�����о����Ƿ����ǵĸ��ڵ��Ƿ���ͬ����ͬ�ھͷ���false
		for (const auto& str : equations)
		{
			if (str[1] == '!')
			{
				if (ufs.FindRoot(str[0] - 'a') == ufs.FindRoot(str[3] - 'a'))
				{
					return false;
				}
			}
		}
		return true;
	}
};