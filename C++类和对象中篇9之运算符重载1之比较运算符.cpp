#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Date
{
public:
	Date(int year = 2021, int month = 6, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	bool operator==(const Date& d2)  //==ÔËËã·ûÖØÔØ
	{
		return _year == d2._year&&_month == d2._month&&_day == d2._day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2021,6,1);
	Date d2(2021,5,31);
	std::cout << (d1 == d2) << std::endl;
	return 0;
}