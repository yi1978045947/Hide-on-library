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
	String s2(s1);  //导致一块空间释放了两次，对一个对象的删除，增加会改变另一个对象
	return 0;
}