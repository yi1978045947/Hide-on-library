#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<vector>
class Solution
{
public:
	int singleNumber(std::vector<int>& nums)
	{
		int arr[32] = { 0 };
		//ͳ��������32������λ��ÿһλ1���ֵĴ���
		for (size_t i = 0; i < nums.size(); i++)
		{
			for (size_t j = 0; j < 32; j++)
			{
				if (nums[i] & (1 << j))
				{
					arr[j]++;
				}
			}
		}
		int ret = 0;
		for (size_t i = 0; i < 31; i++)
		{
			if (arr[i] % 3 == 1)
			{
				ret = ret | (1 << i);
			}
		}
		return ret;
	}
};
int main()
{
	return 0;
}