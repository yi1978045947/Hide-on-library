#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
class Test
{
public:
	Test()
		:_data(0)
	{
		std::cout << "Test():" << std::endl;
	}
	~Test()
	{
		std::cout << "~Test():" << std::endl;
	}
private:
	int _data;
};
void Test2()
{
	//申请一个Test类型的空间
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);
	//申请十个Test类型的空间
	Test* p2 = (Test*)malloc(sizeof(Test)* 10);
	free(p2);
}
void Test3()
{
	//申请一个Test类型的对象
	Test* p1 = new Test;

	//申请10个Test类型的对象
	Test* p2 = new Test[10];
}
int main()
{
	Test T;
	Test3();
	return 0;
}