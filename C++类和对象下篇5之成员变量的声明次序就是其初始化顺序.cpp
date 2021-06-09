#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class A
{
public:
	A(int a)
		:_a1(a)
		, _a2(_a1)
	{}

	void Print() {
		std::cout << _a1 << " " << _a2 << std::endl;
	}
private:
	int _a2;
	int _a1;
};
int main() {
	A aa(1);
	aa.Print();
	return 0;
}