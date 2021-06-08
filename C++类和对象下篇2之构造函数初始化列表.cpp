#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year),
		_month(month),
		_day(day)
	{}
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
	Date d1(2021, 6, 7);
	d1.Display();
	return 0;
}