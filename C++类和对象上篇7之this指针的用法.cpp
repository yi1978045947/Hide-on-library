#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
// 1.��������ܱ���ͨ����
// 2.����������������������
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