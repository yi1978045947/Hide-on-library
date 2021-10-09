#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<string>
using namespace std;

namespace yyw
{
	class string
	{
	public:
		string(const char* str = "")
			:_str(new char[strlen(_str) + 1])
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
			//检查是否自己给自己赋值
			if (this != &s)
			{
				char* tmp = new char[strlen(s._str) + 1]; //开辟新空间
				strcpy(tmp, s._str);                      //把s1的数据拷贝到新空间上
				delete[] _str;                            //删除旧空间
				_str = tmp;                               //赋值新空间
			}
		}

		~string()
		{
			if (_str != nullptr)
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

		string operator+(const string& s)
		{
			char* tmp = new char[strlen(_str) + strlen(s._str) + 1]; //开辟新空间
			strcpy(tmp, _str);                                    //拷贝旧空间数据到新空间上
			strcpy(tmp + strlen(_str), s._str);                   //拷贝要链接的数据到新空间上
			string strTmp(tmp);                                   //拷贝构造临时对象
			return strTmp;                                        //返回临时对象
		}
	private:
		char* _str;
	};
}
int main()
{
	return 0;
}	

#include<algorithm>