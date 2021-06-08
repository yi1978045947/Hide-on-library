#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Time
{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		std::cout << "Time()" << std::endl;
	}
private:
	int _hour;
};

class Date
{
public:
	Date(int day)
		:_day(day)
	{}
private:
	int _day;
	Time _t;
};
int main()
{
	Date d(1);
	return 0;
}