#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;
// �����ͷ�new��Դ
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

// ����malloc����Դ���ͷ�
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

// �ر��ļ�ָ��
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
	// shared_ptr: ������ǰ�ȫ��---������Ϊ�˱�֤shared_ptr����İ�ȫ��
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
				// ��ʱֻ�е�ǰ�ոմ����õ�1��������ʹ�ø÷���Դ
				_pCount = new int(1);
			}
		}

		~shared_ptr()
		{
			Release();
		}

		/////////////////////////////////////////////////////////
		// ����ָ�����Ƶ���Ϊ
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
		// �û�������Ҫ��ȡ���ü���
		int use_count()const
		{
			return *_pCount;
		}

		///////////////////////////////////////////////////////////
		// ���ǳ������ʽ���������ü���
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
				// �ں�sp����֮ǰ��this��Ҫ��֮ǰ��״̬���
				Release();

				// this�Ϳ��Ժ�sp������Դ�Լ�������
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
		T* _ptr;        // ����������Դ��
		int* _pCount;   // ָ�������ü����Ŀռ�---��¼����ʹ����Դ�Ķ���ĸ���
		mutex* _pMutex; // Ŀ�ģ���֤�����ü����Ĳ����ǰ�ȫ��
	};
}


void TestSharedPtr()
{
	yyw::shared_ptr<int> sp1(new int);
	yyw::shared_ptr<int> sp2(sp1);

	yyw::shared_ptr<int> sp3(new int);
	yyw::shared_ptr<int> sp4(sp3);

	sp3 = sp2;   // sp2��sp3����ͬһ����Դ��

	sp4 = sp2;   // sp2��sp4����ͬһ����Դ��
}


// ����﷨Ҳ��C++11�µ��﷨���ڶ����Ա����ʱ�����Ծ͵س�ʼ��
struct A
{
	int a = 0;
	int b = 0;
	int c = 0;
};


// �̺߳���
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

	// t1�������ͺͶ�Ӧ���̰߳�һ����
	thread t1(ThreadFunc, sp, 10000);
	thread t2(ThreadFunc, sp, 10000);

	// �̵߳ȴ�
	t1.join();
	t2.join();


	// 1. ����᲻�����----->shared_ptr�Ƿ�ȫ---û�б�����
	// 2. A �����еĸ�����Ա��ֵ�ǲ��Ƕ���20000
	cout << sp->a << endl;
	cout << sp->b << endl;
	cout << sp->c << endl;
}
/////////////////////////////////////////////////////////
// ���ñ�׼���е�shared_ptr�����в���
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

	// t1�������ͺͶ�Ӧ���̰߳�һ����
	thread t1(ThreadFuncstd, sp, 10000);
	thread t2(ThreadFuncstd, sp, 10000);

	// �̵߳ȴ�
	t1.join();
	t2.join();


	// 1. ����᲻�����----->shared_ptr�Ƿ�ȫ---û�б�����
	// 2. A �����еĸ�����Ա��ֵ�ǲ��Ƕ���20000
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