#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
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
	// 最简单的lambda表达式, 该lambda表达式没有任何意义
	[]{};

	int a = 3;
	int b = 4;
	//实现a+b的lambda的表达式

	auto add1 = [](int x1, int x2)->int{return x1 + x2;};
	cout << add1(a, b) << endl;

	//直接捕捉a,b
	//auto add2=[a,b]()->int{return a+b;};
	auto add2 = [a, b]()->int{return a + b; };
	cout << add2() << endl;
	
	//不捕捉
	auto swap1 = [](int& x1, int& x2)
	{
		int tmp = x1;
		x1 = x2;
		x2 = tmp;
	};
	swap1(a, b);
	cout << a << " " << b << endl;
	 
	//引用捕捉
	auto swap2 = [&]()
	{
		int tmp = a;
		a = b;
		b = tmp;
	};
	swap2();
	cout << a << " " << b << endl;


	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	
	//这里会发现lamber表达式在这些地方更方便
	std::sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)
	{
		return g1._price > g2._price;
	});
	std::sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)
	{
		return g1._num > g2._num;
	});


	return 0;
}