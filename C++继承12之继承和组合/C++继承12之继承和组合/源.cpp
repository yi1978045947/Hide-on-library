#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;

// Car��BMW Car��Benz����is-a�Ĺ�ϵ
class Car{
protected:
	string _colour = "��ɫ"; // ��ɫ
	string _num = "��ABIT00"; // ���ƺ�
};
class BMW : public Car
{
public:
	void Drive() 
	{ 
		cout << "�ÿ�-�ٿ�" << endl; 
	}
};
class Benz : public Car
{
public:
	void Drive() 
	{
		cout << "����-����" << endl; 
	}
};
// Tire��Car����has-a�Ĺ�ϵ
class Tire
{
protected:
	string _brand = "Michelin"; // Ʒ��
	size_t _size = 17; // �ߴ�
};
class Car
{
protected:
	string _colour = "��ɫ"; // ��ɫ
	string _num = "��ABIT00"; // ���ƺ�
	Tire _t; // ��̥
};
#include <iostream>
using namespace std;
int main()
{
	int array[12] = { 31, 59, 90, 120, 151, 181, 212,
		243, 273, 304, 334, 365 };
	int year;
	int month;
	int day;
	int sum = 0;
	while (cin >> year >> month >> day)
	{
		sum = 0;
		sum += array[month - 2];
		sum += day;
		if (month > 2)
		{
			if ((year % 4 == 0 && year % 100 != 0)
				|| year % 400 == 0)
			{
				sum += 1;
			}
		}
		cout << sum << endl;
	}
}
