#include<iostream>
#include<assert.h>
namespace yyw
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		string(const char* str = "")        //构造函数
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//string s2(s1)
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			this->swap(tmp);
		}

		//s1=s3
		string& operator=(const string& s) //(string s)
		{
			//this->swap(s);
			string tmp(s._str);
			this->swap(tmp);
			return *this;
		}

		void swap(string &s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		~string()                         //析构函数
		{
			if (_str)
			{
				delete[] _str;
				_size = _capacity = 0;
				_str = nullptr;
			}
		}
		
		//string(const string& s)   //拷贝构造

		void push_back(char ch)           //增加字符
		{
			if (_size == _capacity)      //增加空间
			{
				size_t newcapacity = _capacity == 0 ? 6 : _capacity * 2;
				char* tmp = new char[newcapacity + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = newcapacity;
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';    //_size的位置设置为\0
		}
		void append(char* str)     //追加字符串
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)   //注意不能按2倍去增容
			{
				size_t newcapacity = _size + len;
				char* tmp = new char[newcapacity + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = newcapacity;
			}
			strcpy(_str + _size, str);
			_size += len;
			//_str[_size + len] = '\0'; strcpy已经把\0拷贝过去了
		}

		//s1+='ch' s1就是this
		string& operator+=(char ch)
		{
			this->push_back(ch);
			return *this;
		}
		//s1+="ch" s1就是this
		string& operator+=(char* ch)
		{
			this->append(ch);
			return *this;
		}

		string& insert(size_t pos, char ch)       //在pos位置插入字符
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				char* tmp = new char[newcapacity + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				//delete[] _str;  //注意这里不能写反了
				_capacity = newcapacity;
			}
			size_t end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				end--;
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}
		string& insert(size_t pos, char* str)     //在pos位置插入字符串
		{
			assert(pos < _size);
			size_t len = strlen(str);
			if (_size + len>_capacity)
			{
				size_t newcapacity = _size + len;
				char* tmp = new char[newcapacity + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = newcapacity;
			}
			size_t end = _size;
			while (end >= (int)pos)
			{
				_str[end + len] = _str[end];   //这里是挪len个不是1个
				end--;
			}

			//strncpy也可以
			//strncpy(_str + pos, str, len);
			//strcpy会把\0拷贝过去，不可以

			//写个循环从pos依次往后放
			for (size_t i = 0; i < len; i++)
			{
				_str[pos] = str[i];
				pos++;
			}

			_size += len;
			//返回自己
			return *this;
		}

		string& erase(size_t pos, size_t len=npos)
		{
			assert(pos < _size);
			if (len >= _size - pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t i = pos + len;
				while (i <= _size)
				{
					_str[i - len] = _str[i];
					i++;
				}
				_size = _size - len;
			}
			return *this;
		}

		size_t find(char ch, size_t pos)     //在pos位置查找字符
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(char* str, size_t pos)   //在pos位置查找字符串
		{
			char* p = strstr(_str, str);
			if (p == NULL)
			{
				return npos;
			}
			else
			{
				return (p - str);
			}
		}

		void resize(size_t newsize, char ch = '\0')  //填充字符ch
		{
			if (newsize<_size)   //第三种情况
			{
				_str[newsize] = '\0';
				_size = newsize;
			}
			else 
			{
				if (newsize > _capacity)   //增加容量
				{
					size_t newcapacity = newsize;
					char* tmp = new char[newcapacity];
					strcpy(tmp, _str);
					delete[]_str;
					_str = tmp;
					_capacity = newcapacity;
				}
				for (size_t i = _size; i < newsize; i++)  //把字符ch往_size后面填
				{
					_str[i] = ch;
				}
				_size = newsize;
				_str[_size] = '\0';
			}
		}

		iterator begin()                //iterator迭代器的原理
		{
			return _str;
		}
		iterator end()
		{
			return (_str + _size);
		}

		const char* c_str()
		{
			return _str;
		}

		char& operator[](size_t i)   //重载[]可以遍历输出字符串，加&是既可以读，也可以写
		{
			assert(i < _size);
			return _str[i];
		}
		const char& operator[](size_t i) const
		{
			assert(i < _size);
			return _str[i];
		}

		//s1<s s1就是this
		bool operator<(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret < 0;
		}
		bool operator<=(const string& s)
		{
			return *this<s || *this == s;
		}
		bool operator>(const string& s)
		{
			return !(*this <= s);
		}
		bool operator>=(const string& s)
		{
			return !(*this < s);
		}
		bool operator==(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret == 0;
		}
		bool operator!=(const string& s)
		{
			return !(*this == s);
		}

		bool empty()
		{
			return _size == 0;
		}
		size_t size()                   //求字符串的大小
		{
			return _size;
		}
		size_t capacity()              //求字符串的容量
		{
			return _capacity;
		}

	private:
		char* _str;
		size_t _size;              //已经有多少个有效字符个数
		size_t _capacity;          //能存多少个有效字符个数 \0不是有效字符，\0是标识结束的字符

		static size_t npos;       //insert用的位置
	};
	size_t string::npos = -1;

	std::ostream& operator<<(std::ostream& _out, string& s) 	//重载输出运算符<<
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			std::cout << s[i];
		}
		return _out;
	}
	std::istream& operator>>(std::istream& _in, string &s)     //重载输入运算符<<
	{
		//for (size_t i = 0; i < s.size(); i++)  错误写法
		//{
		//	std::cin >> s[i];
		//}
		while (1)
		{
			char ch;
			ch = _in.get();
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			else
			{
				s += ch;
			}
		}
		return _in;
	}
	//std::istream& operator>>(std::istream& _in, string &s)     //重载输入运算符<<
	//{
	//	//for (size_t i = 0; i < s.size(); i++)  错误写法
	//	//{
	//	//	std::cin >> s[i];
	//	//}
	//	while (1)
	//	{
	//		char ch;
	//		ch = _in.get();
	//		if ( ch == '\n')
	//		{
	//			break;
	//		}
	//		else
	//		{
	//			s += ch;
	//		}
	//	}
	//	return _in;
	//}
	void TestString1()
	{
		string s1;
		string s2("bit");
		for (size_t i = 0; i < s1.size(); i++)
		{
			std::cout << s1[i] << " ";
		}
		std::cout << std::endl;
		for (size_t i = 0; i < s2.size(); i++)
		{
			std::cout << s2[i] << " ";
		}
		std::cout << std::endl;
	}
	void TestString2()
	{
		string s1;
		string s2("bit");
		std::cout << s1 << std::endl;
		std::cout << s2 << std::endl;

		s1.push_back('b');
		std::cout << s1 << std::endl;

		s2.push_back(' ');
		std::cout << s2 << std::endl;

		s1.append("hha");
		std::cout << s1 << std::endl;
		s2.append("education");
		std::cout << s2 << std::endl;

		s1 += 'a';
		std::cout << s1 << std::endl;
		s2 += "a";
		std::cout << s2 << std::endl;

		s2.insert(1, 'a');
		std::cout << s2 << std::endl;

		s2.insert(1, "www");
		std::cout << s2 << std::endl;
		
		std::cout << s2.size() << std::endl;
		std::cout << s2.capacity() << std::endl;
	}
	void TestString3()
	{
		string s1;
		std::cin >> s1;
		std::cout << s1 << std::endl;
	}
}