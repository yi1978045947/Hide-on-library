#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
// ��������ָ���ԭ���������һ����
// RAII + operator*()/operator->() + ��ν��ǳ�������⣿
// RAII: �ܹ���֤��Դ���Ա��Զ��ͷ�
// operator*()/operator->(): ���Ա�֤�����ܹ�����ָ��ķ�ʽ������
// ���ǳ�����ķ�ʽ�����ܱ�֤��Դ�����ͷŶ�ζ�����������������

// �����н��ǳ����������ͬ����׼������˸�������ָ�룺
// C++98: auto_ptr
// C++11: unique_ptr  shared_ptr&weak_tr

// C++98��auto_ptr
namespace yyw
{
	template<class T>
	class auto_ptr
	{
	public:
		//////////////////////////////////////////
		// RAII : ��֤��Դ�����Զ��ͷ�
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		////////////////////////////////////////////////
		// ���ǳ������ʽ����Դת��
		// auto_ptr<int>  ap2(ap1)
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		// ap1 = ap2;
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				// �˴���Ҫ��ap�е���Դת�Ƹ�this
				// ���ǲ���ֱ��ת�ƣ���Ϊthis�����Ѿ�������Դ�ˣ�����ͻ������Դй©
				if (_ptr)
				{
					delete _ptr;
				}
				// ap�Ϳ��Խ�����Դת�Ƹ�this
				_ptr = ap._ptr;
				ap._ptr = nullptr;  // ��ap��֮ǰ�������Դ�Ͽ���ϵ����Ϊap�е���Դ�Ѿ�ת�Ƹ�this��
			}
			return *this;
		}
		/////////////////////////////////////////////
		// �������ָ�����Ƶ���Ϊ
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		T* get()
		{
			return _ptr;
		}

		///////////////////////////////////////////
		// ���ǳ�������⣺auto_ptr�ܷ��������ķ�ʽ�������
	private:
		T* _ptr;
	};
}
int main()
{
	yyw::auto_ptr<int> ap1(new int);
	*ap1 = 100;

	cout << *ap1 << endl;
	yyw::auto_ptr<int> ap2(ap1);
	cout << *ap2 << endl;

	// �����Ƕ�ָ�볣�����֪�������
	int* p1 = new int;
	int* p2(p1);
	*p1 = 10;
	*p2 = 20;
	delete p1;
	p1 = p2 = nullptr;

	// auto_ptr������Դת�Ƶķ�ʽ��Ȼ��ǳ�������������ˣ������������µ�����
	*ap2 = 2000;
	//*ap1 = 1000;   // ������������Ϊap1���е���Դ�Ѿ�ת�����ˣ�ap1���е�ָ��ָ��Ŀ�

	cout << *ap2 << endl;
	//cout << *ap1 << endl;

	yyw::auto_ptr<int> ap3(new int);
	*ap3 = 300;
	cout << *ap3 << endl;

	yyw::auto_ptr<int> ap4(new int);
	*ap4 = 400;
	cout << *ap4 << endl;
	ap3 = ap4;
	cout << *ap3 << endl;
	return 0;
}


