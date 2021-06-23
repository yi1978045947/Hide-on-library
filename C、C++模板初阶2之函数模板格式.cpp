#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
template<class T>
void swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}
int main()
{
	int a = 10;
	int b = 20;
	swap(a, b);
	std::cout << a << " " << b << std::endl;
	float c = 1.0;
	float d = 2.0;
	std::cout << c << " " << d << std::endl;
	swap(c, d);
	char e = 'a';
	char f = 'b';
	swap(e, f);
	std::cout << e << " " << f << std::endl;
	return 0;
}