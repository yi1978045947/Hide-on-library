#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
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
	// ��򵥵�lambda���ʽ, ��lambda���ʽû���κ�����
	[]{};

	int a = 3;
	int b = 4;
	//ʵ��a+b��lambda�ı��ʽ

	auto add1 = [](int x1, int x2)->int{return x1 + x2;};
	cout << add1(a, b) << endl;

	//ֱ�Ӳ�׽a,b
	//auto add2=[a,b]()->int{return a+b;};
	auto add2 = [a, b]()->int{return a + b; };
	cout << add2() << endl;
	
	//����׽
	auto swap1 = [](int& x1, int& x2)
	{
		int tmp = x1;
		x1 = x2;
		x2 = tmp;
	};
	swap1(a, b);
	cout << a << " " << b << endl;
	 
	//���ò�׽
	auto swap2 = [&]()
	{
		int tmp = a;
		a = b;
		b = tmp;
	};
	swap2();
	cout << a << " " << b << endl;


	Goods gds[] = { { "ƻ��", 2.1 }, { "�ཻ", 3 }, { "����", 2.2 }, { "����", 1.5 } };
	
	//����ᷢ��lamber���ʽ����Щ�ط�������
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