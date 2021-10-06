#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

class StackOnly
{
public:
	static StackOnly GetObj()
	{
		return StackOnly();
	}
private:
	StackOnly(){}

	void* operator new(size_t size) = delete;
};
int main()
{
	StackOnly p = StackOnly::GetObj();
	//StackOnly* p = new StackOnly;
	return 0;
}