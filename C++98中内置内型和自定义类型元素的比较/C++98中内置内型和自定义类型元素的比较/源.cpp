#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<functional>
#include<algorithm>

using namespace std;

template<class T>
struct Greater
{
	bool operator()(const T& x1, const T& x2)
	{
		return x1 > x2;
	}
};

template<class T>
bool g2(const T& x1, const T& x2)
{
	return x1 > x2;
}


int x1()
{
	int array[] = { 4, 1, 8, 5, 3, 7, 0, 9, 2, 6 };
	std::sort(array, array + sizeof(array) / sizeof(array[0]));
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;

	std::sort(array, array + sizeof(array) / sizeof(array[0]), Greater<int>());
	Greater<int> g1;
	cout << g1(1, 2) << endl;  //g1是一个对象，这里调用的是operator()实现的比较
	cout << g2(1, 2) << endl;  //g2是一个函数指针，这里调用他指向的函数
	//两者完全不同的对象，但是他们用起来一样
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

struct Goods
{
	string _name;  //名字
	double _price; //价格
	int _num;      //数量
};


struct ComPriceGreater
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._price > g2._price;
	}
};
struct ComNumGreater
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._num > g2._num;
	}
};
int  main()
{
	Goods goods[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	std::sort(goods, goods + sizeof(goods) / sizeof(goods[0]), ComPriceGreater());
	std::sort(goods, goods + sizeof(goods) / sizeof(goods[0]), ComNumGreater());
	return 0;
}