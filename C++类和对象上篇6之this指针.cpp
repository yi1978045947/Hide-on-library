#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
//定义一个日期类
class Date
{
public:
	void InitDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		std::cout << _year << ":" << _month << ":" << _day << std::endl;
	}
private:
	int _year;   //年
	int _month;  //月
	int _day;    //天
};
int main()
{
	Date d1;
	Date d2;
	//d1._year = 2021;
	//d1._month = 5;
	//d1._day = 27;
	d1.InitDate(2021, 5, 27);
	d2.InitDate(2021, 5, 28);
	d1.Print();
	d2.Print();
	return 0;
}