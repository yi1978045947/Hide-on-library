#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
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
	String s1("hello");
	String s2(s1);
}
