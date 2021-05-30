#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Date
{
public:
	Date()                                             //1.无参构造函数
	{
		_year = 1000;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1000, int month = 1, int day = 1)  //2.全缺省构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1; //对象实例化时自动调用构造函数，所以这里不能调用两个构造函数。
	return 0;
}