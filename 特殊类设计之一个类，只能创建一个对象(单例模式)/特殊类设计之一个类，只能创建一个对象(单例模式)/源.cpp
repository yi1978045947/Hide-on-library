#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>

#include<thread>
#include<vector>
#include<Windows.h>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		Sleep(1000);
		if (_pinst == nullptr)
		{
			_pinst = new Singleton;
		}
		return _pinst;
	}
private:
	Singleton()
	{}
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
	static Singleton* _pinst;
};
Singleton* Singleton::_pinst = nullptr;

int main()
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