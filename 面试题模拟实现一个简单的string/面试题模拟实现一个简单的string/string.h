#include<iostream>

//用小写的string必须用命名空间，否则会造成与库里面的string冲突
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

		//s2(s1）
		string(const string& s)
			:_str(new char[strlen(s._str)+1])
		{
				strcpy(_str, s._str);
		}

		//s1=s;
		string& operator=(const string& s)
		{
			//检查是否自己给自己赋值
			if (this != &s)
			{
				char* tmp = new char[strlen(s._str) + 1];
				strcpy(tmp,s._str);   //把s的数据拷贝到新开辟的空间
				delete[] _str;        //把this指向的空间释放掉
				_str = tmp;           //指向新空间
			}
			return *this;
		}

		~string()
		{
			if(_str)
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
		size_t _size;
		char* _str;
	};
	void TestString1()
	{
		string s1;
		string s2("hello");
		for (size_t i = 0; i < s2.size(); i++)
		{
			std::cout << s2[i] << " ";
		}
		std::cout << std::endl;
		s1 = s2;
		for (size_t i = 0; i < s1.size(); i++)
		{
			std::cout << s1[i] << " ";
		}
	}
}
//C++ 的一个常见面试题是让你实现一个 String 类，限于时间，不可能要求具备 std::string 的功能，
//但至少要求能正确管理资源。具体来说：
//能像 int 类型那样定义变量，并且支持赋值、复制。
//能用作函数的参数类型及返回类型。
//能用作标准库容器的元素类型，即 vector / list / deque 的 value_type。（用作 std::map 的 key_type 是更进一步的要求，本文从略）。
//换言之，你的 String 能让以下代码编译运行通过，并且没有内存方面的错误。