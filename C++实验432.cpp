#define _CRT_SECURE_NO_WARNINGS   1
#include<iostream>
using namespace std;

//int main() //������cout
//{
//	cout << "c++"<< endl;
//	return 0;
//}

//int main()
//{
//	char name[50];
//	cout << "�����������:";
//	cin >> name;
//	cout << "����:" << name << endl;
//	return 0;
//}

void fun()
{
	static int j = 0;
	++j;
	cout << j << endl; 
}
int main()
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		fun();
	}
	return 0;
}