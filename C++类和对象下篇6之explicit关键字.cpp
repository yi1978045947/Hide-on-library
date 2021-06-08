#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Date
{
public:
	explicit Date(int year)
		:_year(year)
	{}
	void Display()
	{
		std::cout << _year <<std::endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2018);
	d1.Display();
	d1 = 2019;
	d1.Display();
	return 0;
}