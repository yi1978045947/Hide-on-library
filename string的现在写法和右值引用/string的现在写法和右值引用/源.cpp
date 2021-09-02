#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string.h>

namespace yyw
{
	class string
	{
		string(const char* str = "")
		:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);
		}

		//s2(s1)
		string(const string& s)
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}

		//s2=s1
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* _Pstr = new char[strlen(s._str) + 1];
				strcpy(_Pstr, s._str);
				delete[] _str;
				_str = _Pstr;
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}
