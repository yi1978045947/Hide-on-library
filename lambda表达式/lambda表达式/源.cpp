#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<functional>
#include<algorithm>

using namespace std;

struct Goods
{
	string _name;  //����
	double _price; //�۸�
	int _num;      //����
};
int main()
{
	Goods gds[] = { { "ƻ��", 2.1 }, { "�ཻ", 3 }, { "����", 2.2 }, { "����", 1.5 } };
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& l, const Goods& r)
		->bool
	{
		return l._price < r._price;
	});
	return 0;
}