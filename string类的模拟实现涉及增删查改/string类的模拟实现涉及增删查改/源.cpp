#define _CRT_SECURE_NO_WARNINGS   1
#include"string.h"
int main()
{
	yyw::TestString1();

	yyw::string s3("hello");
	yyw::string::iterator it = s3.begin();
	while (it != s3.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	for (auto e : s3)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	yyw::TestString2();

	yyw::TestString3();
	return 0;
}