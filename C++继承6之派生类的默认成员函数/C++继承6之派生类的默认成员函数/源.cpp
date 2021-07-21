#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	Person(const char* name = "张三")
		:_name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name;   //姓名
};

class Student :public Person
{
public:
	//s1()
	Student(const char* name, int num)   //派生类的构造函数调用父类的构造函数初始化
		:Person(name)
		,_num(num)
	{
		cout << "Student()" << endl;
	}
	//s2(s1)
	Student(const Student& s)
		:Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}
	//s1=s2;
	Student& operator=(const Student& s)
	{
		cout << "Student& operator=(const Student& s)" << endl;
		if (this != &s)
		{
			//派生类的operator=与基类的operator=构成同名函数会发生隐藏
			Person::operator=(s);
			_num = s._num;
		}
		return *this;
	}

	~Student()
	{
		
		cout << "~Student()" << endl;
		Person::~Person();
	}
protected:
	int _num;  //学号
};
int main()
{
	Student s1("哈士奇", 101);
	//Student s2(s1);
	//Student s3("阿拉", 102);
	//s1 = s3;
	return 0;
}