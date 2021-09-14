#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
namespace yyw
{
	// auto_ptrʵ��ԭ��:RAII + operator*()/operator->() +  ���ǳ������ʽ����Դ����Ȩ��(�ͷ�Ȩ��)ת��
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _owner(false)
		{
			if (_ptr)
			{
				_owner = true;
			}
		}
		~auto_ptr()
		{
			if (_ptr&&_owner)
			{
				delete _ptr;
				_owner = false;
			}
		}

		// �������ָ�����Ƶ���Ϊ
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* get()
		{
			return _ptr;
		}

		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
			,_owner(ap._owner)
		{
			ap._owner = false;
		}
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr&&_owner)
				{
					delete _ptr;
				}
				_ptr = ap._ptr;
				_owner = ap._owner;
				ap._owner = false;
			}
			return *this;
		}
	private:
		T* _ptr;
		bool _owner;  // true: ��ǰ�������Դ�����ͷ�Ȩ��   fase: ��ǰ�������Դû���ͷ�Ȩ��
	};
}
void TestAutoPtr()
{
	yyw::auto_ptr<int> ap1(new int);
	*ap1 = 100;

	yyw::auto_ptr<int> ap2(ap1);

	// �����Ƕ�ָ�볣�����֪�������
	int* p1 = new int;
	int* p2(p1);
	*p1 = 10;
	*p2 = 20;
	delete p1;
	p1 = p2 = nullptr;


	// auto_ptr������Դת�Ƶķ�ʽ��Ȼ��ǳ�������������ˣ������������µ�����
	if (ap2.get())
		*ap2 = 2000;
	if (ap1.get())
		*ap1 = 1000;   // ������������Ϊap1���е���Դ�Ѿ�ת�����ˣ�ap1���е�ָ��ָ��Ŀ�


	yyw::auto_ptr<int> ap3(new int);
	*ap3 = 300;

	yyw::auto_ptr<int> ap4(new int);
	*ap4 = 400;

	ap3 = ap4;

	//////////////////////////////////////
	// ������ȱ��---���Իᵼ��Ұָ��
	if (true)
	{
		yyw::auto_ptr<int> ap5(ap2);
		*ap5 = 100;
		*ap2 = 200;
		*ap1 = 300;

		// ������if��������ʱ��ap5�Ѿ����������Դ�ͷŵ���
		// ��ap1��ap2�����Ͳ�֪�������ڲ���ָ���ΪҰָ����
	}

	// ���ͨ��ap1��ap2�ٷ�����Դʱ������ͻ������
	*ap2 = 10;
}

int main()
{
	TestAutoPtr();
	return 0;
}