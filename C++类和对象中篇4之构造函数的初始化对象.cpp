#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Time
{
public:
	Time()
	{
		std::cout << "Time()" << std::endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	void print()
	{
		std::cout << _year << ":" << _month << ":" << _day << std::endl;
	}
private:
	//�������Ͳ���ʼ��
	int _year;
	int _month;
	int _day;

	//�Զ������ͳ�ʼ��
	Time _t;
};
int main()
{
	Date d;
	d.print();
	return 0;
}