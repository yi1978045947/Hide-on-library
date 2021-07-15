#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
class Date
{
public:
	Date()
	{
		cout << "Date()" << endl;
		_year = 0;
		_month = 0;
		_day = 0;
	}
	void print()
	{
		cout << _year << ":" << _month << ":" << _day << endl;
	}
	~Date()
	{
		cout << "~Date()" << endl;
	}
	
	//d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//d2==d1
	bool operator==(const Date& d)
	{
		return _year == d._year&&_month == d._month&&_day == d._day;
	}
	//d2>d1
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year&&_month > d._month)
		{
			return true;
		}
		else if (_year == d._year&&_month == d._month&&_day > d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//d2=d1
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;

	//Time _t;
};
int main()
{
	Date d1;
	Date d2(d1);
	Date d3;
	d3 = d1;
	return 0;
}