#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Date
{
public:
	Date(int year = 2021, int month = 06, int day = 01)
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
	Date d1;
	d1.Display();
	Date d2(d1);  //调用默认拷贝构造函数
	d2.Display();
	return 0;
}