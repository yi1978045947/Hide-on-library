#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
#include < string>
using namespace std;
class Person
{
public:
	void print()
	{
		cout << _name << endl;
	}
protected:
	string _name = "ÕÅÈý";
private:
	int _age;
};
//class Student :private Person
//class Student :protected Person
class Student :public Person
{
protected:
	int _stunum;
};
int main()
{
	Student s1;
	s1.print();
	return 0;
}