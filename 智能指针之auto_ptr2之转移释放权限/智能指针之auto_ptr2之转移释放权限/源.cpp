#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
namespace yyw
{
	// auto_ptr实现原理:RAII + operator*()/operator->() +  解决浅拷贝方式：资源管理权限(释放权利)转移
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

		// 对象具有指针类似的行为
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
		bool _owner;  // true: 当前对象对资源具有释放权利   fase: 当前对象对资源没有释放权利
	};
}
void TestAutoPtr()
{
	yyw::auto_ptr<int> ap1(new int);
	*ap1 = 100;

	yyw::auto_ptr<int> ap2(ap1);

	// 和我们对指针常规的认知有区别的
	int* p1 = new int;
	int* p2(p1);
	*p1 = 10;
	*p2 = 20;
	delete p1;
	p1 = p2 = nullptr;


	// auto_ptr采用资源转移的方式虽然将浅拷贝的问题解决了，但是引用了新的问题
	if (ap2.get())
		*ap2 = 2000;
	if (ap1.get())
		*ap1 = 1000;   // 代码会崩溃，因为ap1当中的资源已经转移走了，ap1当中的指针指向的空


	yyw::auto_ptr<int> ap3(new int);
	*ap3 = 300;

	yyw::auto_ptr<int> ap4(new int);
	*ap4 = 400;

	ap3 = ap4;

	//////////////////////////////////////
	// 致命的缺陷---可以会导致野指针
	if (true)
	{
		yyw::auto_ptr<int> ap5(ap2);
		*ap5 = 100;
		*ap2 = 200;
		*ap1 = 300;

		// 再来开if的作用域时，ap5已经将管理的资源释放掉了
		// 而ap1和ap2根本就不知道，其内部的指针称为野指针了
	}

	// 如果通过ap1和ap2再访问资源时，代码就会出问题
	*ap2 = 10;
}

int main()
{
	TestAutoPtr();
	return 0;
}