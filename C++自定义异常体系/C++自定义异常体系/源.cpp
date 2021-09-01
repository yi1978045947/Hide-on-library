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
	string _errmsg;             //��������
	int _errid;                 //������
	//stack<string> _st         //����ջ֡
};

class SqlException :public Exception
{
public:
	SqlException(const char* errmsg, int errid)
		:Exception(errmsg, errid)
	{}
	virtual string what()
	{
		return "���ݿ����:" + _errmsg;
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
		return "�������:" + _errmsg;
	}
};
void ServerStart()
{
	//ģ��һ�������׳��쳣����
	if (rand() % 8 == 0)
	{
		throw SqlException("���ݿ�����ʧ��", 1);

	}
	if (rand() % 7 == 0)
	{
		throw NetWorkException("��������ʧ��", 3);
	}

	cout << "��������" << endl;
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
			cout << "δ֪�쳣" << endl;
		}
	}
	return 0;
}