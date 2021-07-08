#include<iostream>

//��Сд��string�����������ռ䣬����������������string��ͻ
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

		//s2(s1��
		string(const string& s)
			:_str(new char[strlen(s._str)+1])
		{
				strcpy(_str, s._str);
		}

		//s1=s;
		string& operator=(const string& s)
		{
			//����Ƿ��Լ����Լ���ֵ
			if (this != &s)
			{
				char* tmp = new char[strlen(s._str) + 1];
				strcpy(tmp,s._str);   //��s�����ݿ������¿��ٵĿռ�
				delete[] _str;        //��thisָ��Ŀռ��ͷŵ�
				_str = tmp;           //ָ���¿ռ�
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
//C++ ��һ������������������ʵ��һ�� String �࣬����ʱ�䣬������Ҫ��߱� std::string �Ĺ��ܣ�
//������Ҫ������ȷ������Դ��������˵��
//���� int ���������������������֧�ָ�ֵ�����ơ�
//�����������Ĳ������ͼ��������͡�
//��������׼��������Ԫ�����ͣ��� vector / list / deque �� value_type�������� std::map �� key_type �Ǹ���һ����Ҫ�󣬱��Ĵ��ԣ���
//����֮����� String �������´����������ͨ��������û���ڴ淽��Ĵ���