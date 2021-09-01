#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<math.h>
#include<string>
using namespace std;

class Exception
{
public:
	Exception(const char* errmsg, int errid)
		:_errmsg(errmsg)
		, _errid(errid)
	{}
	virtual string what() = 0;
protected:
	string _errmsg;             //错误描述
	int _errid;                 //错误码
	//stack<string> _st         //调用栈帧
};

class SqlException :public Exception
{
public:
	SqlException(const char* errmsg, int errid)
		:Exception(errmsg, errid)
	{}
	virtual string what()
	{
		return "数据库错误:" + _errmsg;
	}
};

class NetWorkException :public Exception
{
public:
	NetWorkException(const char* errmsg, int errid)
		:Exception(errmsg, errid)
	{}
	virtual string what()
	{
		return "网络错误:" + _errmsg;
	}
};
void ServerStart()
{
	//模拟一下问题抛出异常报错
	if (rand() % 8 == 0)
	{
		throw SqlException("数据库启动失败", 1);

	}
	if (rand() % 7 == 0)
	{
		throw NetWorkException("网络连接失败", 3);
	}

	cout << "正常运行" << endl;
}

int main()
{
	for (size_t i = 0; i < 100; i++)
	{
		try
		{
			ServerStart();
		}
		catch (Exception& e)
		{
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "未知异常" << endl;
		}
	}
	return 0;
}