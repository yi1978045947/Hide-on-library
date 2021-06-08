#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Date
{
public:
	Date(int year, int month, int day) //构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Display()
	{
		std::cout << _year << ":" << _month << ":" << _day << std::endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	//在创建对象时，编译器通过调用构造函数，
	//给对象中各个成员变量一个合适的初始值
	Date d1(2021, 6, 7);
	d1.Display();
	return 0;
}