#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Date
{
public:
	Date()                              //�޲ι��캯��
	{

	}
	Date(int year, int month, int day) //���ι��캯��
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
	Date d1;               //�����޲ι��캯��
	d1.Display();
	Date d2(2021, 5, 30);  //���ô��ι��캯��
	d2.Display();
	Date d3();            //����������
	return 0;
}