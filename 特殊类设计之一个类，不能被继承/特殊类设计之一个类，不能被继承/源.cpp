#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

class NoInherit final
{
public:
	static NoInherit GetInstance()
	{
		return NoInherit();
	}
private:
	NoInherit()
	{}
};
int main()
{
	NoInherit a = NoInherit::GetInstance();
	return 0;
}