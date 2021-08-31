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
	cout << g1(1, 2) << endl;  //g1��һ������������õ���operator()ʵ�ֵıȽ�
	cout << g2(1, 2) << endl;  //g2��һ������ָ�룬���������ָ��ĺ���
	//������ȫ��ͬ�Ķ��󣬵�������������һ��
	for (auto e : array)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}

struct Goods
{
	string _name;  //����
	double _price; //�۸�
	int _num;      //����
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
	Goods goods[] = { { "ƻ��", 2.1 }, { "�ཻ", 3 }, { "����", 2.2 }, { "����", 1.5 } };
	std::sort(goods, goods + sizeof(goods) / sizeof(goods[0]), ComPriceGreater());
	std::sort(goods, goods + sizeof(goods) / sizeof(goods[0]), ComNumGreater());
	return 0;
}