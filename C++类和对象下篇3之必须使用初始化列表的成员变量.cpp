#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class A
{
public:
	A(int x)
	{
		std::cout << "A(int x)" << std::endl;
		_x = x;
	}
private:
	int _x;
};

class Date
{
public:
	// �������ɣ�һ������ĵ�����Ա�����ڳ�ʼ���б���
	// �����ʵ���ǳ�ʼ���б��ʼ���ͺ������ڳ�ʼ����ͬ�ĵط���Ҳ�����ļ�ֵ����
	Date(int year = 0, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)

		, _n(10)           //const��Ա����
		, _ref(year)       //���ó�Ա����
		, _a(1)           // ��ʾȥ����
	{}

private:
	// ��Ա��������
	int _year;
	int _month;
	int _day;

	// ���Ǳ����ڶ����ʱ���ʼ��
	const int _n;
	int& _ref;
	A _a;
};

int main()
{
	Date d1;
	//Date d2;

	return 0;
}