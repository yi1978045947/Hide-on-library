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
			//����Ƿ��Լ����Լ���ֵ
			if (this != &s)
			{
				char* tmp = new char[strlen(s._str) + 1]; //�����¿ռ�
				strcpy(tmp, s._str);                      //��s1�����ݿ������¿ռ���
				delete[] _str;                            //ɾ���ɿռ�
				_str = tmp;                               //��ֵ�¿ռ�
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
			char* tmp = new char[strlen(_str) + strlen(s._str) + 1]; //�����¿ռ�
			strcpy(tmp, _str);                                    //�����ɿռ����ݵ��¿ռ���
			strcpy(tmp + strlen(_str), s._str);                   //����Ҫ���ӵ����ݵ��¿ռ���
			string strTmp(tmp);                                   //����������ʱ����
			return strTmp;                                        //������ʱ����
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