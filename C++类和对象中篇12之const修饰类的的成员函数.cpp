#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
class Date
{
public:
	void Display()
	{
		cout << "Display ()" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
	void Display() const
	{
		cout << "Display () const" << endl;
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl << endl;
	}
private:
	int _year; // Äê
	int _month; // ÔÂ
	int _day; // ÈÕ
};
int main()
{
	Date d1;
	d1.Display();
	const Date d2;
	d2.Display();
	return 0;
}

