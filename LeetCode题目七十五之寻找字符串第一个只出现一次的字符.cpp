#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;
class Sloution
{
public:
	int firstUniqChar(string s)
	{
		//使用映射的方法统计次数
		int count[26] = { 0 };
		for (auto e : s)
		{
			count[e - 'a']++;
		}
		for (size_t i = 0; i < s.size(); i++)
		{
			count[s[i] - 'a'];
		}
		for (size_t i = 0; i < s.size(); i++)
		{
			if (count[s[i] - 'a'] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};
int main()
{
	return 0;
}