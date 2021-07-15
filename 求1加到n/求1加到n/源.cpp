#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
class Sum
{
public:
	Sum()
	{
		_sum = _sum + _i;
		_i++;
	}
	static void Init()
	{
		_i = 1;
		_sum = 0;
	}
	static int GetSum()
	{
		return _sum;
	}
private:
	static int _i;
	static int _sum;
};
int Sum::_i = 1;
int Sum::_sum = 0;
class Sloution
{
public:
	int Sum_Sloution(int n)
	{
		//Sum a[n];
		Sum::Init();   //防止第二次调用进来时_i和_sum的值不是1和0
		Sum *p = new Sum[n];
		return Sum::GetSum();
	}
};
int main()
{
	Sloution st;
	cout << st.Sum_Sloution(5) << endl;
	cout << st.Sum_Sloution(5) << endl;
	return 0;
}