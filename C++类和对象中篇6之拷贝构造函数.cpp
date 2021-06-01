#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Date
{
public:
	Date(int year = 2021, int month = 5, int day = 31)  //构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d2)
	{
		_year = d2._year;
		_month = d2._month;
		_day = d2._day;
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
	Date d1;
	d1.Display();
	Date d2(d1);  //把d1拷贝给d2
	d2.Display();
}