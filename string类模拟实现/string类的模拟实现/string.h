#include<iostream>
namespace yyw
{
	class string
	{
	public: 
		//string()            //无参构造函数
		//	:_str(nullptr)
		//{}

		//string(char* str)  //有参构造函数
		//	:_str(str)
		//{}

		string()
			:_str(new char[1])
		{
			_str[0] = '\0';
		}
		string(char* str)   //构造函数在堆上开辟一段strlen+1的空间+1是c_str
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str); //strcpy会拷贝\0过去
		}

		//string(char* str="")   //构造函数在堆上开辟一段strlen+1的空间+1是c_str
		//	:_str(new char[strlen(str) + 1])
		//{
		//	strcpy(_str, str); //strcpy会拷贝\0过去
		//}
		size_t size()
		{
			return strlen(_str);
		}
		bool empty()
		{
			return _str == nullptr;
		}
		char& operator[](size_t i)  //用引用返回不仅可以读字符，还可以修改字符
		{
			return _str[i];
		}

		~string()          //析构函数
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

		//string s2(s1) s1就是s,s2就是this，this指向新开辟的空间，
		string(const string& s)  //原来空间s._str  //深拷贝,拷贝构造函数
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}

		
		string& operator=(const string& s) //赋值运算符重载,深拷贝
		{
			if (this != &s)
			{
				char* p_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
				delete[] _str;
				_str = p_str;;
			}
			return *this;
		}
		const char* c_str() //返回C的格式字符串
		{
			return _str;
		}

	private:
		char* _str;
	};
	void TestString1()
	{
		string s1("hello");
		string s2;
		for (size_t i = 0; i < s1.size(); i++)
		{
			s1[i] += 1;
			std::cout << s1[i] << " ";
		}
		std::cout << std::endl;
		for (size_t i = 0; i < s2.size(); i++)
		{
			s2[i] += 1;
			std::cout << s2[i] << " ";
		}
		std::cout << std::endl;
	}

	void TestString2()
	{
		string s1("hello");
		string s2(s1);
		std::cout << s1.c_str() << std::endl;
		std::cout << s2.c_str() << std::endl;

		string s3("world");
		s1 = s3; //调试点这里，析构也是两次
		std::cout << s1.c_str() << std::endl;
		std::cout << s3.c_str() << std::endl;
	}
}



