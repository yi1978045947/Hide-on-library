#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string.h>
using namespace std;
class Solution
{
public:
	bool IsLetter(char s)
	{
		if ((s >= 'a'&&s <= 'z') || (s >= 'A'&&s <= 'Z'))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string reverseOnlyLetters(string s)
	{
		size_t begin = 0;
		size_t end = s.size() - 1;
		while (begin < end)
		{
			while (begin < end&&IsLetter(s[begin] == false))
			{
				begin++;
			}
			while (begin < end&&IsLetter(s[end]) == false)
			{
				end--;
			}
			swap(s[begin], s[end]);
			begin++;
			end--;
		}
		return s;
	}
};
int main()
{
	return 0;
}