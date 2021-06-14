#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
class Date; // 前置声明
class Time
{
	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
public:
	Time(int hour, int minute, int second)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	void SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main()
{
	Date d;
	d.SetTimeOfDate(2021,6,8);
	return 0;
}

//class Time
//{
//	friend class Date;   // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//	void f(Date& d)
//	{
//		d._year = 1;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//	friend class Time;
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		_t._hour = 1;
//	}
//
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d;
//	d.SetTimeOfDate(2021, 6, 8);
//	return 0;
//}
