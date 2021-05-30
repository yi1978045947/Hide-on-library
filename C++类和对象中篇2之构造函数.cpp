#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Date
{
public:
	Date()                              //无参构造函数
	{

	}
	Date(int year, int month, int day) //带参构造函数
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
	Date d1;               //调用无参构造函数
	d1.Display();
	Date d2(2021, 5, 30);  //调用带参构造函数
	d2.Display();
	Date d3();            //函数的声明
	return 0;
}