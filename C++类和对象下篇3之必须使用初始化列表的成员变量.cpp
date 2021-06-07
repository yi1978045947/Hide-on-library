#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class A
{
public:
	A(int x)
	{
		std::cout << "A(int x)" << std::endl;
		_x = x;
	}
private:
	int _x;
};

class Date
{
public:
	// 可以理解成，一个对象的单个成员变量在初始化列表是
	// 这个其实算是初始化列表初始化和函数体内初始化不同的地方，也是他的价值体现
	Date(int year = 0, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)

		, _n(10)           //const成员变量
		, _ref(year)       //引用成员变量
		, _a(1)           // 显示去调用
	{}

private:
	// 成员变量声明
	int _year;
	int _month;
	int _day;

	// 他们必须在定义的时候初始化
	const int _n;
	int& _ref;
	A _a;
};

int main()
{
	Date d1;
	//Date d2;

	return 0;
}