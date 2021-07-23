#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;

// Car和BMW Car和Benz构成is-a的关系
class Car{
protected:
	string _colour = "白色"; // 颜色
	string _num = "陕ABIT00"; // 车牌号
};
class BMW : public Car
{
public:
	void Drive() 
	{ 
		cout << "好开-操控" << endl; 
	}
};
class Benz : public Car
{
public:
	void Drive() 
	{
		cout << "好坐-舒适" << endl; 
	}
};
// Tire和Car构成has-a的关系
class Tire
{
protected:
	string _brand = "Michelin"; // 品牌
	size_t _size = 17; // 尺寸
};
class Car
{
protected:
	string _colour = "白色"; // 颜色
	string _num = "陕ABIT00"; // 车牌号
	Tire _t; // 轮胎
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
