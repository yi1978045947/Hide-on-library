#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Date
{
public:
	void SetDate(int year, int month, int day)  //��ʼ������
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
����Date�࣬����ͨ��SetDate���еķ����������������ݣ��������ÿ�δ������󶼵��ø÷���������
Ϣ��δ���е��鷳�����ܷ��ڶ��󴴽�ʱ���ͽ���Ϣ���ý�ȥ�أ�
���캯����һ������ĳ�Ա������������������ͬ, ���������Ͷ���ʱ�ɱ������Զ����ã���֤ÿ�����ݳ�Ա
���� һ�����ʵĳ�ʼֵ�������ڶ��������������ֻ����һ�Ρ�