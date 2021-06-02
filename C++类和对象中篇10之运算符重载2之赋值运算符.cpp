#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Date
{
public:
	Date(int year = 2021, int month = 6, int day = 1) //构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d2)                             //拷贝构造函数
	{
		_year = d2._year;
		_month = d2._month;
		_day = d2._day;
	}
	Date& operator = (const Date& d2)               //赋值运算符重载
	{
		if (this != &d2)
		{
			_year = d2._year;
			_month = d2._month;
			_day = d2._day;
		}
		return *this;
	}
	void Display()
	{
		std::cout << _year << ";" << _month << ":" << _day << std::endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	d1.Display();
	Date d2(2021,5,31);
	d2.Display();
	d1 = d2;
	d2.Display();
	d1.Display();
}

