#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
// 1.下面程序能编译通过吗？
// 2.下面程序会崩溃吗？在哪里崩溃
class A
{
public:
	void PrintA()
	{
		std::cout << _a << std::endl;
	}
	void Show()
	{
		std::cout << "Show()" << std::endl;
	}
private:
	int _a;
};
int main()
{
	A* p = nullptr;
	//p->PrintA();
	p->Show();
}