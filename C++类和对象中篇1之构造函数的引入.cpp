#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Date
{
public:
	void SetDate(int year, int month, int day)  //初始化参数
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
	d1.SetDate(2021, 5, 28);
	d1.Display();
	Date d2;
	d2.SetDate(2021, 5, 29);
	d2.Display();
	return 0;
}
对于Date类，可以通过SetDate公有的方法给对象设置内容，但是如果每次创建对象都调用该方法设置信
息，未免有点麻烦，那能否在对象创建时，就将信息设置进去呢？
构造函数是一个特殊的成员函数，名字与类名相同, 创建类类型对象时由编译器自动调用，保证每个数据成员
都有 一个合适的初始值，并且在对象的生命周期内只调用一次。