#include<iostream>
namespace yyw
{
	class string
	{
	public: 
		//string()            //�޲ι��캯��
		//	:_str(nullptr)
		//{}

		//string(char* str)  //�вι��캯��
		//	:_str(str)
		//{}

		string()
			:_str(new char[1])
		{
			_str[0] = '\0';
		}
		string(char* str)   //���캯���ڶ��Ͽ���һ��strlen+1�Ŀռ�+1��c_str
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str); //strcpy�´��\0��ȥ
		}

		//string(char* str="")   //���캯���ڶ��Ͽ���һ��strlen+1�Ŀռ�+1��c_str
		//	:_str(new char[strlen(str) + 1])
		//{
		//	strcpy(_str, str); //strcpy�´��\0��ȥ
		//}
		size_t size()
		{
			return strlen(_str);
		}
		bool empty()
		{
			return _str == nullptr;
		}
		char& operator[](size_t i)  //�����÷��ز������Զ��ַ����������޸��ַ�
		{
			return _str[i];
		}

		~string()          //��������
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}

		//string s2(s1) s1����s,s2����this��thisָ���¿��ٵĿռ䣬
		string(const string& s)  //ԭ���ռ�s._str  //���,�������캯��
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}

		
		string& operator=(const string& s) //��ֵ���������,���
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
		const char* c_str() //����C�ĸ�ʽ�ַ���
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
		s1 = s3; //���Ե��������Ҳ������
		std::cout << s1.c_str() << std::endl;
		std::cout << s3.c_str() << std::endl;
	}
}



