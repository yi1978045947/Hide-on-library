#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<string.h>

namespace yyw
{
	class string
	{
	public:
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		//s2(s1)
		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		//s2=s1
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* p = new char[strlen(s._str) + 1];
				strcpy(p, s._str);
				delete[] _str;
				_str = p;
			}
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

		char& operator[](size_t i)
		{
			return _str[i];
		}

		size_t size()
		{
			return strlen(_str);
		}
	private:
		char* _str;
	};
	void TestString()
	{
		string s1;
		string s2("hello");
		s1 = s2;
		for (size_t i = 0; i < s1.size(); i++)
		{
			std::cout << s1[i] << " ";
		}
		std::cout << std::endl;
		for (size_t i = 0; i < s1.size(); i++)
		{
			std::cout << s2[i] << " ";
		}
		std::cout << std::endl;
	}
}
