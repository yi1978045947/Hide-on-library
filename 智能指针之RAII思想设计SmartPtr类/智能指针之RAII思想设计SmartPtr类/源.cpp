#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

	// �ø���������ָ�����ƵĲ����Ϳ�����
	T& operator*()
	{
		return *_ptr;
	}
	//  -> ֻ��ָ��ָ�������߽ṹ�����Щ������
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;    // �����ཫָ���������
};

struct Date
{
	int _year;
	int _month;
	int _date;
};
int main()
{
	int* p = new int;
	SmartPtr<int> sp1(p);
	cout << *sp1 << endl;

	SmartPtr<int> sp2(new int);
	*sp2 = 10;
	cout << *sp2 << endl;

	SmartPtr<Date> sp3(new Date);
	sp3->_year = 2021;
	sp3->_month = 9;
	sp3->_date = 13;
	cout << sp3->_year << ":" << sp3->_month << ":" << sp3->_date << endl;

	SmartPtr<int> sp4(new int);
	SmartPtr<int> sp5(sp4);
	return 0;
}