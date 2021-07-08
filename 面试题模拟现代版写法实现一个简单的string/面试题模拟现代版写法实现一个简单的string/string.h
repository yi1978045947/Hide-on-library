#include<iostream>
#include<algorithm>
namespace yyw
{
	class string
	{
	public:
		string(const char* str = "")
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);
		}

		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			std::swap(_str, tmp._str);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s._str);
				std::swap(_str, tmp._str);
			}
			return *this;
		}

		string& operator=(string s)
		{
			std::swap(_str, s._str);
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
	void TestString1()
	{
		string s1;
		string s2("hello");
		string s3(s2);
	}
}