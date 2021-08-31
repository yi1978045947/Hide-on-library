#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<functional>
#include<algorithm>

using namespace std;

struct Goods
{
	string _name;  //名字
	double _price; //价格
	int _num;      //数量
};
int main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& l, const Goods& r)
		->bool
	{
		return l._price < r._price;
	});
	return 0;
}