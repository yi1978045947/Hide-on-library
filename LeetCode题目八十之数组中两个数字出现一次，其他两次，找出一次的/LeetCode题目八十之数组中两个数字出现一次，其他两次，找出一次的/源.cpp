#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<vector>
class Solution
{
public:
	std::vector<int> singleNumber(std::vector<int>& nums)
	{
		int val;
		//���������һ�飬�ҳ�������ͬ�����������������������
		for (size_t i = 0; i < nums.size(); i++)
		{
			val = val^nums[i];
		}
		//�ҳ�val�б���λΪ1��λΪi
		size_t i = 0;
		for (i = 0; i < 32; i++)
		{
			if (val&(1 << i))
			{
				break;
			}
		}
		//�ֳ����飬��Ϊval��������ͬ������ģ����и���i�����飬������ͬ����һ���ֳ�������
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
		//����ֵ�Ƿ�������
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