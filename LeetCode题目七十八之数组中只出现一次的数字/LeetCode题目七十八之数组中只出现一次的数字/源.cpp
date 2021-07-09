#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<vector>
using namespace std;
class vector
{
public:
	int singleNumber(std::vector<int>& v)
	{
		int value;
		for (auto e : v)
		{
			value = value^e;
		}
		return value;
	}
};
int main()
{
	return 0;
}