#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Date
{
public:
	Date()                                             //1.�޲ι��캯��
	{
		_year = 1000;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1000, int month = 1, int day = 1)  //2.ȫȱʡ���캯��
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
	Date d1; //����ʵ����ʱ�Զ����ù��캯�����������ﲻ�ܵ����������캯����
	return 0;
}