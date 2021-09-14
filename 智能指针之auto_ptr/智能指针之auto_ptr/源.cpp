#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
// 所有智能指针的原理基本都是一样的
// RAII + operator*()/operator->() + 如何解决浅拷贝问题？
// RAII: 能够保证资源可以被自动释放
// operator*()/operator->(): 可以保证对象能够按照指针的方式来运行
// 解决浅拷贝的方式：可能保证资源不被释放多次而引起代码崩溃的问题

// 由于有解决浅拷贝方案不同，标准库给出了各种智能指针：
// C++98: auto_ptr
// C++11: unique_ptr  shared_ptr&weak_tr

// C++98：auto_ptr
namespace yyw
{
	template<class T>
	class auto_ptr
	{
	public:
		//////////////////////////////////////////
		// RAII : 保证资源可以自动释放
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
		// 解决浅拷贝方式：资源转移
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
				// 此处需要将ap中的资源转移给this
				// 但是不能直接转移，因为this可能已经管理资源了，否则就会造成资源泄漏
				if (_ptr)
				{
					delete _ptr;
				}
				// ap就可以将其资源转移给this
				_ptr = ap._ptr;
				ap._ptr = nullptr;  // 让ap与之前管理的资源断开联系，因为ap中的资源已经转移给this了
			}
			return *this;
		}
		/////////////////////////////////////////////
		// 对象具有指针类似的行为
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
		// 解决浅拷贝问题：auto_ptr能否采用深拷贝的方式来解决？
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

	// 和我们对指针常规的认知有区别的
	int* p1 = new int;
	int* p2(p1);
	*p1 = 10;
	*p2 = 20;
	delete p1;
	p1 = p2 = nullptr;

	// auto_ptr采用资源转移的方式虽然将浅拷贝的问题解决了，但是引用了新的问题
	*ap2 = 2000;
	//*ap1 = 1000;   // 代码会崩溃，因为ap1当中的资源已经转移走了，ap1当中的指针指向的空

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


