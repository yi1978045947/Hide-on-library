#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
	bool IsLetterOrNumber(char ch)
	{
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9'))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isPalindrome(string s)
	{
		for (auto & e : s)
		{
			if (e >= 'a'&&e <= 'z')
			{
				e = e - 32;
			}
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end)
		{
			while (begin < end&&IsLetterOrNumber(s[begin]) == false)
			{
				begin++;
			}
			while (begin < end&&IsLetterOrNumber(s[end]) == false)
			{
				end--;
			}
			if (s[begin] != s[end])
			{
				return false;
			}
			else
			{
				begin++;
				end--;
			}
		}
		return false;
	}
};
int main()
{
	return 0;
}