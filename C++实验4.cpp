//#define _CRT_SECURE_NO_WARNINGS   1
//#include <iostream>
//#include <string>
//using namespace std;
//class Student {
//public:
//	Student(char name) {
//		this->name = name;
//		average = semesterHours = 0;
//	}
//	void addCoure(int hours, float grade) {
//		average = (semesterHours*average + grade);
//		semesterHours += hours;
//		average /= semesterHours;
//	}
//	int getHours() { return semesterHours; }
//	float Average() { return average; };
//	void display() {
//		cout << "name=" << name << "\"" << ",hours=" << semesterHours << ",average=" << average << endl;
//	}
//protected:
//	char name;
//	int semesterHours;
//	float average;
//};
//
//class GraduateStudent :public Student {
//public:
//	int getQualifier() { return qualifierGrade; }
//protected:
//	int qualifierGrade;
//
//};
//
//int main()
//{
//	Student stu('yyy');
//	stu.addCoure(10, 20);
//	stu.getHours();
//	stu.Average();
//	stu.display();
//	return 0;
//}

#include <iostream>
using namespace std;
class A {
public:
	A(int i) :a(i) {}
	void print() {
		cout << a << endl;
	}
	int Geta() {
		return a;
	}
private:
	int a;
};
class B :public A {
public:B(int i = 0, int j = 0) :A(i), a(j), b(i + j) {}
	   void Print() {
		   A::print();
		   cout << b << "," << a.Geta() << endl;
	   }
private:
	int b;
	A a;

};
int main()
{
	B b1(5), b2(10, 20);
	b1.Print();
	b2.Print();
	return 0;
}