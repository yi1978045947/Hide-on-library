#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
//cout现在还讲不清楚，大家先理解记住它的使用
//ostream 类型全局对象 cout
//istream 类型全局对象 cin
//endl    全局的换行符号

struct Person
{
	char name[10];
	int age;
};
int main()
{
	std::cout << "bit education ";
	std::cout << "bit education" << std::endl;
	//cout与cin对比C语言printf\scanf 来说可以自动识别类型(函数重载+运算符重载)
	int a = 10;
	int* p = &a;
	printf("%d,%p\n", a, p);
	std::cout << a << "," << p << std::endl;
	std::cin >> a;
	printf("%d\n", a);
	char str[100];
	std::cin >> str;  //cin不用&,因为引用
	std::cout << str << std::endl;

	struct Person P = { "uzi", 23 };  //格式化输出printf比cout好
	printf("name:%s age:%d\n", P.name, P.age);
	std::cout << "name:" << P.name<<" age:"<< P.age << "\n";
}