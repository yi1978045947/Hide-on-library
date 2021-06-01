#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string.h>
class String
{
public:
	String(const char* str = "Hello")
	{
		_str = (char*)malloc(sizeof(char)+1);
		strcpy(_str, str);
	}
	~String()
	{
		std::cout << "~String()" << std::endl;
		free(_str);
	}
private:
	char* _str;
};
int main()
{
	String s1("Hello");
	String s2(s1);  //����һ��ռ��ͷ������Σ���һ�������ɾ�������ӻ�ı���һ������
	return 0;
}