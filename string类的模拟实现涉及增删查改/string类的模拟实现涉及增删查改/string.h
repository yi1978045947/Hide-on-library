#include<iostream>
#include<assert.h>
namespace yyw
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		string(const char* str = "")        //���캯��
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
		~string()                         //��������
		{
			if (_str)
			{
				delete[] _str;
				_size = _capacity = 0;
				_str = nullptr;
			}
		}
		
		//string(const string& s)   //��������

		void push_back(char ch)           //�����ַ�
		{
			if (_size == _capacity)      //���ӿռ�
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
			_str[_size] = '\0';    //_size��λ������Ϊ\0
		}
		void append(char* str)     //׷���ַ���
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)   //ע�ⲻ�ܰ�2��ȥ����
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
			//_str[_size + len] = '\0'; strcpy�Ѿ���\0������ȥ��
		}

		//s1+='ch' s1����this
		string& operator+=(char ch)
		{
			this->push_back(ch);
			return *this;
		}
		//s1+="ch" s1����this
		string& operator+=(char* ch)
		{
			this->append(ch);
			return *this;
		}

		string& insert(size_t pos, char ch)       //��posλ�ò����ַ�
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				char* tmp = new char[newcapacity + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				//delete[] _str;  //ע�����ﲻ��д����
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
		string& insert(size_t pos, char* str)     //��posλ�ò����ַ���
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
				_str[end + len] = _str[end];   //������Ųlen������1��
				end--;
			}

			//strncpyҲ����
			//strncpy(_str + pos, str, len);
			//strcpy���\0������ȥ��������

			//д��ѭ����pos���������
			for (size_t i = 0; i < len; i++)
			{
				_str[pos] = str[i];
				pos++;
			}

			_size += len;
			//�����Լ�
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

		size_t find(char ch, size_t pos)     //��posλ�ò����ַ�
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
		size_t find(char* str, size_t pos)   //��posλ�ò����ַ���
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

		void resize(size_t newsize, char ch = '\0')  //����ַ�ch
		{
			if (newsize<_size)   //���������
			{
				_str[newsize] = '\0';
				_size = newsize;
			}
			else 
			{
				if (newsize > _capacity)   //��������
				{
					size_t newcapacity = newsize;
					char* tmp = new char[newcapacity];
					strcpy(tmp, _str);
					delete[]_str;
					_str = tmp;
					_capacity = newcapacity;
				}
				for (size_t i = _size; i < newsize; i++)  //���ַ�ch��_size������
				{
					_str[i] = ch;
				}
				_size = newsize;
				_str[_size] = '\0';
			}
		}

		iterator begin()                //iterator��������ԭ��
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

		char& operator[](size_t i)   //����[]���Ա�������ַ�������&�Ǽȿ��Զ���Ҳ����д
		{
			assert(i < _size);
			return _str[i];
		}
		const char& operator[](size_t i) const
		{
			assert(i < _size);
			return _str[i];
		}

		//s1<s s1����this
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
		size_t size()                   //���ַ����Ĵ�С
		{
			return _size;
		}
		size_t capacity()              //���ַ���������
		{
			return _capacity;
		}

	private:
		char* _str;
		size_t _size;              //�Ѿ��ж��ٸ���Ч�ַ�����
		size_t _capacity;          //�ܴ���ٸ���Ч�ַ����� \0������Ч�ַ���\0�Ǳ�ʶ�������ַ�

		static size_t npos;       //insert�õ�λ��
	};
	size_t string::npos = -1;

	std::ostream& operator<<(std::ostream& _out, string& s) 	//������������<<
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			std::cout << s[i];
		}
		return _out;
	}
	std::istream& operator>>(std::istream& _in, string &s)     //�������������<<
	{
		//for (size_t i = 0; i < s.size(); i++)  ����д��
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
	//std::istream& operator>>(std::istream& _in, string &s)     //�������������<<
	//{
	//	//for (size_t i = 0; i < s.size(); i++)  ����д��
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