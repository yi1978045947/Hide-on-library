#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<vector>
#include<thread>
using namespace std;

namespace yyw
{
	//饿汉模式-- 一开始(main函数之前就)创建对象
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			return &_inst;
		}

		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
	private:
		Singleton()
		{}
		static Singleton _inst;
	};

	Singleton Singleton::_inst;
	//static对象是在main函数之前就创建的，这里只有主线程，所以不存在线程安全问题
	int x()
	{
		//cout << Singleton::GetInstance() << endl;
		//cout << Singleton::GetInstance() << endl;
		//cout << Singleton::GetInstance() << endl;

		//存在线程安全问题
		//Singleton copy(*Singleton::GetInstance());

		vector<std::thread> vthread;

		int n = 10;
		for (int i = 0; i < n; i++)
		{
			vthread.push_back(thread([]()
			{
				//cout << this_thread::get_id() << ":";
				cout << Singleton::GetInstance() << endl;
			}));
		}

		for (auto& t : vthread)
		{
			t.join();
		}
		return 0;
	}
}
int main()
{
	yyw::x();
	return 0;
}