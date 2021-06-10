#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Test
{
public:
	static void Fun()
	{
		std::cout << _a << std::endl; //不能访问非静态成员
		std::cout << _b << std::endl; 
	}
private:
	int _a; 
	static int _b; 
};
int main()
{

}