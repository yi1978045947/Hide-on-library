#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<vector>
class Solution
{
public:
	std::vector<int> singleNumber(std::vector<int>& nums)
	{
		int val;
		//所有数异或一遍，找出两个不同数异或结果，其他数被异或掉了
		for (size_t i = 0; i < nums.size(); i++)
		{
			val = val^nums[i];
		}
		//找出val中比特位为1的位为i
		size_t i = 0;
		for (i = 0; i < 32; i++)
		{
			if (val&(1 << i))
			{
				break;
			}
		}
		//分成两组，因为val是两个不同异或来的，所有根据i来分组，两个不同的数一定分成了两组
		int x = 0;
		int y = 0;
		for (size_t j = 0; j < nums.size(); j++)
		{
			if (nums[i] & (1 << i))
			{
				x = x^nums[i];
			}
			else
			{
				y = y^nums[i];
			}
		}
		//返回值是返回数组
		std::vector<int> v;
		v.push_back(x);
		v.push_back(y);
		return v;
	}
};
int main()
{
	return 0;
}