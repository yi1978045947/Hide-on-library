#define _CRT_SECURE_NO_WARNINGS   1
#include <iostream>
using namespace std;
class Test
{
private:
	static int _n;
	int a;
};
int main()
{
	cout << sizeof(Test) << endl;
	return 0;
}