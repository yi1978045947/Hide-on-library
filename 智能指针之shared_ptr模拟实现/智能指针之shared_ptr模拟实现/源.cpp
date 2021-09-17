#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
// 负责释放new资源
template<class T>
class DFDef
{
public:
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}
};

// 负责：malloc的资源的释放
template<class T>
class Free
{
public:
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			free(ptr);
			ptr = nullptr;
		}
	}
};

// 关闭文件指针
class FClose
{
public:
	void operator()(FILE* & ptr)
	{
		if (ptr)
		{
			fclose(ptr);
			ptr = nullptr;
		}
	}
};


#include <mutex>

namespace yyw
{
	// shared_ptr: 自身才是安全的---加锁：为了保证shared_ptr自身的安全性
	template<class T, class DF = DFDef<T>>
	class shared_ptr
	{
	public:
		//////////////////////////////////////////////////////
		// RAII
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pCount(nullptr)
			, _pMutex(new mutex)
		{
			if (_ptr)
			{
				// 此时只有当前刚刚创建好的1个对象在使用该份资源
				_pCount = new int(1);
			}
		}

		~shared_ptr()
		{
			Release();
		}

		/////////////////////////////////////////////////////////
		// 具有指针类似的行为
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* Get()
		{
			return _ptr;
		}

		//////////////////////////////////////////////////////////
		// 用户可能需要获取引用计数
		int use_count()const
		{
			return *_pCount;
		}

		///////////////////////////////////////////////////////////
		// 解决浅拷贝方式：采用引用计数
		shared_ptr(const shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pCount(sp._pCount)
			, _pMutex(sp._pMutex)
		{
			AddRef();
		}

		shared_ptr<T, DF>& operator=(const shared_ptr<T, DF>& sp)
		{
			if (this != &sp)
			{
				// 在和sp共享之前，this先要将之前的状态清空
				Release();

				// this就可以和sp共享资源以及计数了
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				_pMutex = sp._pMutex;
				AddRef();
			}

			return *this;
		}

	private:
		void AddRef()
		{
			if (nullptr == _ptr)
				return;

			_pMutex->lock();
			++(*_pCount);
			_pMutex->unlock();
		}

		void Release()
		{
			if (nullptr == _ptr)
				return;

			bool isDelete = false;
			_pMutex->lock();

			if (_ptr && 0 == --(*_pCount))
			{
				// delete _ptr;
				DF df;
				df(_ptr);
				delete _pCount;
				_pCount = nullptr;
				isDelete = true;
			}

			_pMutex->unlock();

			if (isDelete)
			{
				delete _pMutex;
			}
		}
	private:
		T* _ptr;        // 用来接收资源的
		int* _pCount;   // 指向了引用计数的空间---记录的是使用资源的对象的个数
		mutex* _pMutex; // 目的：保证对引用计数的操作是安全的
	};
}


void TestSharedPtr()
{
	yyw::shared_ptr<int> sp1(new int);
	yyw::shared_ptr<int> sp2(sp1);

	yyw::shared_ptr<int> sp3(new int);
	yyw::shared_ptr<int> sp4(sp3);

	sp3 = sp2;   // sp2和sp3共享同一份资源了

	sp4 = sp2;   // sp2和sp4共享同一份资源了
}


// 这个语法也是C++11新的语法：在定义成员变量时，可以就地初始化
struct A
{
	int a = 0;
	int b = 0;
	int c = 0;
};


// 线程函数
void ThreadFunc(yyw::shared_ptr<A>& sp, int n)
{
	for (int i = 0; i < n; ++i)
	{
		yyw::shared_ptr<A> copy(sp);
		copy->a++;
		copy->b++;
		copy->c++;
	}
}



#include <thread>
void TestSharedPtrSafe()
{
	yyw::shared_ptr<A> sp(new A);

	// t1对象将来就和对应的线程绑定一起了
	thread t1(ThreadFunc, sp, 10000);
	thread t2(ThreadFunc, sp, 10000);

	// 线程等待
	t1.join();
	t2.join();


	// 1. 代码会不会崩溃----->shared_ptr是否安全---没有崩溃：
	// 2. A 对象中的各个成员的值是不是都是20000
	cout << sp->a << endl;
	cout << sp->b << endl;
	cout << sp->c << endl;
}
/////////////////////////////////////////////////////////
// 利用标准库中的shared_ptr来进行测试
#include <memory>
void ThreadFuncstd(shared_ptr<A>& sp, int n)
{
	for (int i = 0; i < n; ++i)
	{
		shared_ptr<A> copy(sp);
		copy->a++;
		copy->b++;
		copy->c++;
	}
}

void TestSharedPtrSafestd()
{
	shared_ptr<A> sp(new A);

	// t1对象将来就和对应的线程绑定一起了
	thread t1(ThreadFuncstd, sp, 10000);
	thread t2(ThreadFuncstd, sp, 10000);

	// 线程等待
	t1.join();
	t2.join();


	// 1. 代码会不会崩溃----->shared_ptr是否安全---没有崩溃：
	// 2. A 对象中的各个成员的值是不是都是20000
	cout << sp->a << endl;
	cout << sp->b << endl;
	cout << sp->c << endl;
}

int main()
{
	TestSharedPtrSafestd();

	shared_ptr<int>  sp(new int);

	TestSharedPtrSafe();

	TestSharedPtr();
	return 0;
}